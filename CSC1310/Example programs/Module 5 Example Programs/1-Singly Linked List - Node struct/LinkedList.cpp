/*******************************************************
	Title:  	LinkedList.cpp
	Date:  		2/08/2019
	Updated:	9/19/2025
	Author: 	April Crockett
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains a Node
				structure variable
********************************************************/

#include <iostream>  
#include "LinkedList.h"
using namespace std;

// isEmpty returns true if the list has no nodes 
// and false if it does
bool LinkedList::isEmpty(){
	if(!head)
		return true;
	else
		return false;
}

//getLength() returns the number of nodes in the list.
int LinkedList::getLength(){
	int counter = 0;
	Node *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail){
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

//returns the node value at a given integer position
double LinkedList::getNodeValue(int position){
	Node *nodePtr;
	if(!head){
		return -1;
	}
	else{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		while(nodePtr != NULL && position >= currentPos){
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;				
		}
	}
	return -1;
}

//**************************************************
// appendNode appends a node containing the        *
// value passed into num, to the end of the list.  *
//**************************************************
void LinkedList::appendNode(double num){
	Node *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new Node;
	newNode->value = num;
	newNode->next = NULL;

	// If there are no nodes in the list make 
	// newNode the first node.
	if (!head ){
		head = newNode;
		tail = newNode;
	}
	else{  // Otherwise, insert newNode at end.
	
		//set the current last node's next pointer 
		//to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

//insert a new node at the integer position passed 
//to this function
void LinkedList::insertNode(int position, double num)
{
	Node *nodePtr;
	Node *newNode;
	
	newNode = new Node;
	newNode->value = num;
	
	if(!head) //no nodes in list
	{
		if(position != 0){
			//can't insert node at position (>0) if there is 
			//not already a node
			cout << "\n\nUnable to insert a node at ";
			cout << " position " << position << " because ";
			cout << "there are currently no nodes in the list. ";
			cout << "I am inserting this node at position 0.\n";
		}
		head = newNode;
		tail = newNode;
	}
	else if(position == 0) //inserting new head
	{
		//The line below was wrong and caused me to "lose" the old head node
		//newNode->next = head->next;
		newNode->next = head; //fixed!
		head = newNode;
	}
	else{ //inserting somewhere else in list that isn't head
		nodePtr = head;
		int nodeCount = 0;
		while(nodePtr != tail && nodeCount < position){
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}
		
		//now nodePtr is positioned 1 node BEFORE the 
		//node we want to insert
		if(nodePtr->next == NULL) //appending new node to end
			tail = newNode;
			
		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
void LinkedList::displayList() const
{
	Node *nodePtr;  // To move through the list
	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr){
			// Display the value in this node.
			cout << nodePtr->value << ", ";

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************
void LinkedList::deleteNode(double num){
	Node *nodePtr;       // To traverse list
	Node *previousNode;  // To point to previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num){
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->value != num){  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr){
			if(nodePtr == tail){
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}


//searches for a value (num) and returns the 
//position or -1 if can't be found
int LinkedList::search(double num)
{
	Node *nodePtr;  // To move through the list
	int position;

	// Position nodePtr at the head of the list.
	nodePtr = head;
	position = 0;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr != NULL){
		//see if this node matches the value
		if(nodePtr->value == num)
			return position;
		
		position++; //increment position

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return -1; //node couldn't be found
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
LinkedList::~LinkedList(){
	Node *nodePtr;   // To traverse the list
	Node *nextNode;  // To point to the next node

	cout << "\nI am in the destructor function. Removing all remaining nodes:";
	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL){
		// Save the address of the next node.
		nextNode = nodePtr->next;
		cout << "\nDeleting the node with value ";
		cout << nodePtr->value;
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	cout << endl << endl;
}

