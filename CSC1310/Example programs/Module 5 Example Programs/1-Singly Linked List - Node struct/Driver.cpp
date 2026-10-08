/********************************************************
	Title:  	Driver.cpp
	Date:  		2-24-2021
	Updated:	9-19-2025
	Author: 	April Crockett
	Purpose:	To demonstrate a Singly-Linked List using 
				a LinkedList class that contains a 
				ListNode structure variable
*********************************************************/

#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList list;
	cout << "\n\nAppending a few nodes (2.5, 7.9, and 12.6)\n";
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);
	
	cout << "\nDisplaying the list, which has ";
	cout << list.getLength() << " nodes.\n";
	list.displayList();
	
	cout << "\nInserting node 9.4 in position 1.\n";
	list.insertNode(1, 9.4);
	cout << "\nDisplaying the list, which has ";
	cout << list.getLength() << " nodes.\n";
	list.displayList();
	
	cout << "\nInserting node 1.6 in position 0.\n";
	list.insertNode(0, 1.6);
	cout << "\nDisplaying the list, which has ";
	cout << list.getLength() << " nodes.\n";
	list.displayList();
	
	cout << "\nAppending another node with a duplicate value of 1.6.\n";
	list.appendNode(1.6);
	cout << "\nDisplaying the list, which has ";
	cout << list.getLength() << " nodes.\n";
	list.displayList();
	
	cout << "\nDeleting nodes with 12.6 and 1.6.\n";
	list.deleteNode(12.6);
	list.deleteNode(1.6);
	
	cout << "\nDisplaying the list, which has ";
	cout << list.getLength() << " nodes.\n";
	list.displayList();
	
	return 0;
}
