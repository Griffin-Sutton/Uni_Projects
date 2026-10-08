/*******************************************************************
	Title: LinkedList.h
	Author:	Griffin Sutton 
	Date: October 7th, 2026
	Purpose: Define linkedList and its functions to be 
             used to store tracks as a struct
*******************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Track.h"

using namespace std;

class LinkedList
{
	private:
		// Declare a structure for the Linked List Node
		struct Node
		{
			Track value; 
			Node *next;  	// To point to the next Node
		}; 
		Node *head;		//List head pointer
		Node *tail;		//List tail pointer
        int length;     //amount of nodes in the list

	public:
		// Constructor
		LinkedList(){ 
			head = NULL; 
			tail = NULL;
            length = 0;
		}

		// Destructor (deallocates all Nodes)
		~LinkedList(){
            Node *current = head;
            Node *nextNode;
            while (current){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

        //Add a new Node to the end of the list
        void appendNode(const Track &t){
            Node *newNode;  // To point to a new Node

            // Allocate a new Node and store num there.
            newNode = new Node;
            newNode->value = t;
            newNode->next = NULL;

            // If there are no Nodes in the list make 
            // newNode the first Node.
            if (!head ){
                head = newNode;
                tail = newNode;
            }
            else{  // Otherwise, insert newNode at end.
            
                //set the current last Node's next pointer 
                //to the new Node
                tail->next = newNode;
                
                //now the tail is the new Node
                tail = newNode;
            }
            length++;
        }

        int getLength() const {
            return length;
        }

        //Display the Track at the position chosen
		void displayNode(int position) const{
			if (position < 0 || position >= length){
				std::cout << "\nThere is no Track at position " << position << ".\n";
				return;
			}
			Node *current = head;
			for (int i = 0; i < position; i++)
				current = current->next;
 
			std::cout << "\nTrack at position " << position << ":\n"
			          << current->value << std::endl;
		}
};

#endif