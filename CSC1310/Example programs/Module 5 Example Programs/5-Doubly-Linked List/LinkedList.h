/*****************************************************************
	Title:  	LinkedList.h - Class Specification File for 
				LinkedList Class
	Date:  		2-8-2019
	Author: 	April Crockett
	Purpose:	A Doubly-Linked List implemented in a
				LinkedList class that contains a Node
				structure variable
******************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/*****************************************************************
							LinkedList Class
******************************************************************/
#include <iostream>
using namespace std;


class LinkedList
{
	private:
		// Declare a structure for the list
		struct Node
		{
			double value;           	// The value in this node
			Node *next;  	// To point to the next node
			Node *previous;	// To point to the previous node
		}; 

		Node *head;		// List head pointer
		Node *tail;		//List tail pointer

	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (similar to a typical RemoveAll function)
		~LinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		double getNodeValue(int);
		void appendNode(double);
		void insertNode(int, double);
		void deleteNode(double);
		void displayList() const;
};

#endif