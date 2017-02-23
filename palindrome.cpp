
#include <string>
#include <iostream>
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

// Recursively push the string, character by character, onto the given stack
void stackPush(stack<char> & stk, string str)
{
	// Return if the string is empty
	if(str == "")
	{
		return;
	}

	// Get the first char in the string
	char c = str[0];

	// Check that the char is alphanumeric
	if(isalpha(c) || isdigit(c))
	{
		// Push the uppercase char
		stk.push(toupper(c));
	}

	// Recursive call
	stackPush(stk, str.substr(1));	
}

// Recursively push the string, character by character, onto the given queue
void queuePush(queue<char> & que, string str)
{
	// Return if the string is empty
	if(str == "")
	{
		return;
	}

	// Get the first char in the string
	char c = str[0];

	// Check that the char is alphanumeric
	if(isalpha(c) || isdigit(c))
	{
		// Push the uppercase char
		que.push(toupper(c));
	}

	// Recursive call
	queuePush(que, str.substr(1));
}

// Recursively pops the queue and stack and compares the popped chars
void popCompare(stack<char> & stk, queue<char> & que, int length)
{
	// Check if the stack/queue is empty
	if(stk.is_empty() || que.is_empty())
	{
		cout << -1 << endl;
		return;
	}
	
	// Get the next char values
	char c1 = stk.peek();
	char c2 = que.peek();

	// Compare the char values
	if(c1 != c2)
	{
		// no match so output the index
		cout << length - stk.length << endl;

		// Clear the stack and queue and return
		stk.clear();
		que.clear();
		return;
	}

	// Pop the stack and queue
	stk.pop();
	que.pop();

	// Recursive call
	popCompare(stk, que, length);
}

int main()
{
	string s;
	stack <char> stk;
	queue <char> que;

	// Read from the standard input
	while(getline(cin, s) && s != "q")
	{
		// push the stack and queue
		stackPush(stk, s);
		queuePush(que, s);

		// pop and compare the values
		popCompare(stk, que, stk.length);
	}
	
	return 0;
}
