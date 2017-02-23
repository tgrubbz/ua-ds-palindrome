
#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class queue_node
{
public:
	// Hold the templated data
	T data;

	// Pointer to the next node
	queue_node<T> * next = nullptr;

	// Constructor that sets the data and next nodes
	queue_node(T data, queue_node * n) : data(data), next(n) { }

	// Default destructor
	~queue_node() = default;
};

template <class T>
class queue
{
public:
	// Front and back node pointers
	queue_node<T> * front = nullptr;
	queue_node<T> * back = nullptr;

	// Empty constrcutor
	queue() { }

	// Default destructor
	~queue() = default;

	// Property for the length of the queue
	int length = 0;

	// Returns true if the queue is empty
	bool is_empty()
	{
		// Check if the front node pointer is not null
		return !front;
	}

	// Push the tmeplated data to the back of the queue
	void push(T data)
	{
		if(is_empty())
		{
			// Set the front and back pointers to the same new node
			back = front = new queue_node<T>(data, nullptr);
		}
		else
		{
			// Set the back pointer and the next pointer to the new node
			back = back->next = new queue_node<T>(data, nullptr);
		}

		// Increase the length property
		++length;
	}

	void pop()
	{
		if(is_empty())
		{
			// Don't pop if is empty
			return;
		}

		// Get a pointer to the front
		queue_node<T> * temp = front;

		// Set front to front's next pointer
		front = front->next;

		// Delete the temp pointer
		delete temp;

		// Decrement the length
		--length;
	}

	T peek()
	{
		return front->data;
	}

	void clear()
	{
		// While the front is not null, call pop
		while(front)
		{
			pop();
		}
	}
};

#endif
