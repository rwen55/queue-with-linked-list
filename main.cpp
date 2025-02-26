#include "Queue.h"

int main() {
	// initializing the queue
	Queue* queue1 = new Queue;
	cout << "Creating a New Queue:" << endl;
	// pushing values into the queue
	queue1->enqueue(0);
	queue1->enqueue(1);
	queue1->enqueue(2);
	queue1->enqueue(3);
	queue1->enqueue(4);
	queue1->enqueue(5);
	// printing the queue
	queue1->print();
	// checking if the queue is sorted or not
	queue1->isSorted() == true
		? cout << "The queue is sorted in ascending order." << endl << endl
		: cout << "The queue is not sorted in ascending order." << endl << endl;
	// dequeueing the front value
	cout << "Leaving the Queue: " << queue1->dequeue() << endl << endl;
	cout << "Printing the Queue after Dequeuing:" << endl;
	queue1->print();
	// printing the front and back values of the queue
	cout << "The Front of the Queue: " << queue1->front() << endl;
	cout << "The Back of the Queue: " << queue1->back() << endl << endl;
	// printing the element at a given index
	int index = 3;
	queue1->peek(index) != -1
		? cout << "The element in index " << index << ": " << queue1->peek(index) << endl << endl
		: cout << "The queue does not contain this index." << endl << endl;
	// checking if the queue contains a given value and printing the index it is in
	int find = 5;
	queue1->contains(find)
		? cout << "The queue contains " << find << "." << endl
		: cout << "The queue does not contain " << find << "." << endl;
	queue1->indexOf(find) != -1
		? cout << find << " is in index " << queue1->indexOf(find) << "." << endl << endl
		: cout << "The index of " << find << " was not found in the queue." << endl << endl;
	// converting the queue to an array
	int* array = queue1->toArray();
	cout << "Printing the Queue as an Array:" << endl;
	for (int i = 0; i < queue1->size(); i++)
		cout << array[i] << "  ";
	cout << endl << endl;
	// reversing the queue
	queue1->reverse();
	cout << "Printing the Queue After Reversing:" << endl;
	queue1->print();
	// removing a node at a given index
	queue1->removeAt(index);
	cout << "Printing the Queue After Removing the Element at Index " << index << ":" << endl;
	queue1->print();
	// creating a copy of the queue
	Queue* queue2 = queue1->copy();
	cout << "Printing a Copy of the Queue:" << endl;
	queue2->print();
	// swapping the values of two nodes
	int index2 = 2;
	queue2->swap(index, index2);
	cout << "Printing the Copy of the Queue After Swapping Two Nodes:" << endl;
	queue2->print();
	// checking if the queue is empty or not
	queue1->isEmpty() == true
		? cout << "The queue is empty." << endl << endl
		: cout << "The queue is not empty." << endl << endl;
	// merging queue2 into queue1
	queue1->merge(queue2);
	cout << "Printing the Original Queue after Merging it with the Copy:" << endl;
	queue1->print();
	// clearing the queue
	queue1->clear();
	cout << "Printing the Original Queue After Clearing it:" << endl;
	queue1->print();
	// checking if the queue is empty or not after clearing it (should be)
	queue1->isEmpty() == true
		? cout << "The queue is empty." << endl << endl
		: cout << "The queue is not empty." << endl << endl;
}