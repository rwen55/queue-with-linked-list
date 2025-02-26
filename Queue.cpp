#include "Queue.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}; // constructor to initialize an empty queue

Queue::~Queue() { // deconstructor for clearing memory used by queues after code finishes executing
	node* current = head; // initialize two pointers to the first and second nodes
	node* temp = current->next;

	while (current != nullptr) { // while loop to iterate through the queue and delete all nodes
		delete current;
		current = temp;
		temp = current->next;
	}
	head = nullptr; // set head and tail to nullptr, declaring the queue empty
	tail = nullptr;
}

void Queue::enqueue(int value) { // function to push values into the end (tail) of the queue
	if (head == nullptr) { // checks if the queue is empty
		head = new node(value, nullptr, nullptr); // if empty, initialize the new node at the head and set tail to the head / new node
		tail = head;
	}
	else { // if the queue has 1 or more nodes
		node* back = new node(value, nullptr, tail); // initialize a new node at the end of the queue, pointing next to nullptr and previous to the original tail
		tail->next = back; // set the next node of the old tail node to the newly created node
		tail = back; // point tail to the new end node
	}
}

void Queue::clear() { // function to clear the queue
	node* current = head; // initialize two pointers to the first and second nodes
	node* temp = current->next;

	while (current != nullptr) { // while loop to iterate through the queue and clear it
		delete current;
		current = temp;
		if (current != nullptr) { // check current again after moving it to temp
			temp = current->next; // move temp after confirming current isn't at the end of the queue
		}
	}
	head = nullptr; // set head and tail to nullptr, declaring the queue empty
	tail = nullptr;
}

void Queue::print() { // function to print the queue horizontally
	if (head == nullptr) { // checks if the queue is empty
		cout << "The queue is empty." << endl << endl; // prints empty message and exits the function
		exit(0);
	}
	node* current = head; // initialize a pointer to iterate through the queue
	cout << "FRONT NULL << ";

	while (current != nullptr) { // while loop to iterate through the queue and print each node's value with spacing
		cout << current->data << " << ";
		current = current->next; // moves current to the next node
	}
	cout << "BACK NULL" << endl << endl;
}

void Queue::reverse() { // function to reverse the order of the queue
	if (head == nullptr) {
		cout << "Cannot reverse an empty queue." << endl << endl;
		exit(0);
	}
	node* current = head; // initialize current to hold the position of the queue's new end
	node* left = head; // left used to create new nodes at the start of the queue (creates the reversed queue)
	node* right = head->next; // right used to reference nodes for copying

	while (right != nullptr) { // while loop to iterate through the queue, copying each node and placing it at the front of the queue
		left = new node(right->data, head, nullptr); // initialize a new node with the data of the node at right, pointing next to head and previous to nullptr
		head = left; // point head to the new top node
		right = right->next; // move right to the next node
	}
	current->next = nullptr; // set current->next to nullptr, cutting off the old nodes
	tail = current; // set tail to the end node of the queue (original queue's head)
}

void Queue::removeAt(int index) { // function to remove a node at a given index
	if (this->size() < index || head == nullptr) { // checks if the queue is empty or the given index exceeds the size of the queue
		cout << "Index not found." << endl << endl; // prints error message and exits the function
		exit(0);
	}
	node* current = head; // initialize three pointers to hold the addresses of three subsequent nodes
	node* before = current;
	node* after = current->next;

	for (int i = 0; i < index; i++) { // for loop to find the node at the given index
		before = current; // before = n
		current = current->next; // current = n + 1
		after = after->next; // after = n + 1 + 1
	}

	if (current == head) { // index = 0 (current is at the head)
		after->previous = nullptr; // make the after node the head node
		head = after;
		delete current; // delete the top node
	}
	else if (current == tail) { // index = size - 1 (current is at the tail)
		before->next = nullptr; // make the before node the tail node
		tail = before;
		delete current; // delete the bottom node
	}
	else { // 0 < index < size - 1 (current is somewhere in the middle)
		before->next = after; // connect the before node to the after node
		after->previous = before;
		delete current; // delete the desired node
	}
}

void Queue::swap(int index1, int index2) { // function to swap the values stored in two nodes
	if (this->size() < index1 || this->size() < index2) { // checks if the given indexes are included in the queue
		cout << "At least 1 index was not found." << endl << endl; // prints an error message and exits the function if not
		exit(0);
	}
	node* current1 = head; // initializing two pointers to hold the addresses of the nodes with the desired indexes
	node* current2 = head;

	for (int i = 0; i < index1; i++) // for loop to find the node corresponding to index1
		current1 = current1->next;
	for (int j = 0; j < index2; j++) // for loop to find the node corresponding to index2
		current2 = current2->next;

	int temp = current1->data; // use a temp variable to help swap the data stored in the two nodes
	current1->data = current2->data;
	current2->data = temp;
}

void Queue::merge(Queue* other) { // function to merge another queue into the function-calling queue
	if (other->head == nullptr) // checks if the other queue is empty, therefore nothing to merge
		exit(0);

	node* current = other->head; // initialize a pointer to the head of the other queue

	while (current != nullptr) { // while loop to iterate through the other queue, enqueueing its nodes into the original queue
		this->enqueue(current->data); // enqueue each node into the original queue
		current = current->next; // move current to the next node
	}
}

int Queue::dequeue() { // function to return the value of the front node and remove it from the queue
	int temp; // temp variable to hold the value of the node for returning before it's deleted
	if (head == nullptr) // checks if the queue is empty, therefore nothing to dequeue or return
		exit(0);
	else if (head->next == nullptr) { // checks if the queue only has 1 node
		node* current = head; // initialize a pointer to the only node before moving head and tail
		head = nullptr; // point head and tail to nullptr, declaring the queue empty
		tail = nullptr;
		temp = current->data; // store the node's value in temp for returning
		delete current; // delete the solo node
	}
	else { // if the queue has 2 or more nodes
		node* current = head; // initialize a pointer to the top node
		head = head->next; // move head to the 2nd node in the queue
		temp = current->data; // store the top node's value in temp for returning
		delete current; // delete the top node
	}
	return temp; // return the value of the top node
}

int Queue::front() { // function to return the value of the front node
	if (head == nullptr) // checks if the queue is empty, therefore returning nothing
		exit(0);

	return head->data;
}

int Queue::back() { // function to return the value of the end node
	if (head == nullptr) // checks if the queue is empty, therefore returning nothing
		exit(0);

	return tail->data;
}

int Queue::peek(int index) { // function to return the value of a node at a given index
	if (this->size() < index || index < 0) // checks if the index is valid for the queue
		return -1;

	node* current = head; // initialize a pointer to iterate through the queue and return the value of its node
	for (int i = 0; i < index; i++) // for loop to find the node corresponding to the given index
		current = current->next; // moves current until the corresponding node is found

	return current->data; // returns the value found at the given index
}

int Queue::indexOf(int value) { // function to search the queue for a given value and return the index where it is stored
	if (head == nullptr) // checks if the queue is empty, meaning it can't possibly contain the value
		return -1;

	node* current = head; // initialize current and i to iterate through the queue and keep track of the index
	int i = 0;

	while (current != nullptr) { // while loop to iterate through the queue to check its nodes for the given value
		if (current->data == value) // if a node with the desired value is found, return its index
			return i;
		i++; // increment i to the next index and move current to the next node
		current = current->next;
	}
	return -1; // returns -1 if the while loop executes without retuning i, meaning the given value was not found
}

int* Queue::toArray() { // function to return the queue as an array
	if (head == nullptr) { // checks if the queue is empty
		int* array = new int; // returns an empty dynamic array
		return array;
	}
	int* array = new int[this->size()]; // initialize a dynamic array with the same size as the queue
	node* current = head; // initialize current and i to iterate through the queue and array
	int i = 0;

	while (current != nullptr) { // while loop to iterate through the queue, copying each node to its corresponding array index
		array[i] = current->data; // copies the data stored in the current node to the array
		i++; // increment i to the next index and move current to the next node
		current = current->next;
	}
	return array; // returns the newly copied array
}

int Queue::size() { // function to return the size of the queue
	int count = 0; // initialize count to keep track of the size
	node* current = head;

	while (current != nullptr) { // while loop to iterate through the queue with current to find its size
		count++; // increment count at every node
		current = current->next; // move current to the next node
	}
	return count; // return the size of the queue after counting each node
}

bool Queue::contains(int value) { // function to return true if the queue contains a given value, false if it doesn't
	if (head == nullptr) // checks if the queue is empty
		return false; // returns false because an empty queue can't have a value

	node* current = head;

	while (current != nullptr) { // while loop to iterate through the queue, checking each node for the value
		if (current->data == value) // if the current node contains the given value, return true
			return true;
		current = current->next; // move current to the next node
	}
	return false; // if the while loop completes without returning, it doesn't have the value, return false
}

bool Queue::isEmpty() { // function to return true if the queue is empty, false if it isn't
	if (head == nullptr) // checks if the queue is empty
		return true; // if the queue is empty, return true
	return false; // assume it isn't empty, return false
}

bool Queue::isSorted() { // function to return true if the queue is sorted in ascending order, false if it isn't
	if (head == nullptr) // checks if the queue is empty
		return false; // if the queue is empty, it can't be sorted?

	node* current = head; // initialize current to iterate through the loop, checking adjacent nodes

	while (current->next != nullptr) { // while loop to check if the queue is sorted, ends loop with current at the last node
		if (current->data > current->next->data) // checks if the current node's data is greater than the next node's data
			return false; // if the current node's data is greater, the queue isn't sorted, return false
		current = current->next; // move current to the next node if the current node's data is less than the next
	}
	return true; // if the while loop completes without returning false, it is sorted, return true
}

Queue* Queue::copy() { // function to return a copy of "this" queue
	if (head == nullptr) { // checks if the queue is empty
		cout << "Cannot copy an empty queue." << endl << endl; // can't copy an empty queue, exit the function
		exit(0);
	}
	Queue* qCopy = new Queue; // initialize qCopy to hold the copied nodes of the original queue
	node* current = this->head; // initialize current to the head of the original queue

	while (current != nullptr) { // while loop to enqueue copied nodes into qCopy
		qCopy->enqueue(current->data); // call enqueue to append nodes with current's data to qCopy
		current = current->next; // move current to the next node
	}
	return qCopy; // return the newly copied queue
}
