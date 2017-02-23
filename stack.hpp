
#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class node
{
public:
	// Templated data
	T data;

	// Next pointer
	node * next = nullptr;

	// Constructor sets data and the next node pointer
	node(T data, node * n) : data(data), next(n) { }

	// Default destructor
	~node() = default;
};

template <class T>
class stack
{
private:
	// Pointer to the top of the stack
	node<T> * top = nullptr;

public:
	// Empty constructor
	stack() { }

	// Defualt destructor
	~stack() = default;

	// Clears the stack
	void clear() { while(top) pop(); }
	void pop();
	void push(T data);

	// Returns the data from the top pointer
	T peek() { return top->data; }

	// Checks if the stack is empty
	bool is_empty() { return !top; }
	int length = 0;
};

template <class T>
void stack<T>::pop()
{
	// Don't pop if the stack is empty
	if(!top) return;

	// Create a temp pointer to top
	node<T> * temp = top;

	// Set top to top's next pointer
	top = top->next;

	// Delete the temp ponter
	delete temp;

	// Decrement the length
	--length;
}

template <class T>
void stack<T>::push(T data)
{
	// Set top to the new node
	top = new node<T>(data, top);

	// Increment the length
	++length;
}

#endif
