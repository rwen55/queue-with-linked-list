#pragma once

#include <iostream>

using namespace std;

class node {
public:
	int data; // holds the value of the node
	node* next; // holds the address of the next node
	node* previous; // holds the address of the previous node
	node() { data = 0; next = nullptr; previous = nullptr; } // constructor to initialize an empty node
	node(int v, node* next_node, node* previous_node) { this->data = v, this->next = next_node, this->previous = previous_node; } // constructor to initialize a desired node
};

class Queue {
public:
	// constructor + deconstructor
	Queue();
	~Queue();
	// void functions
	void enqueue(int);
	void clear();
	void print();
	void reverse();
	void removeAt(int);
	void swap(int, int);
	void merge(Queue*);
	// int functions
	int dequeue();
	int front();
	int back();
	int peek(int);
	int indexOf(int);
	int* toArray();
	int size();
	// bool functions
	bool contains(int);
	bool isEmpty();
	bool isSorted();
	// queue copy function
	Queue* copy();
	// pointers for top and bottom of the queue
	node* head;
	node* tail;
};