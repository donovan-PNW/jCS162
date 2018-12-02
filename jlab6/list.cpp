#include "list.h"
//put your implementation of LinkedList class here

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

void LinkedList::addAtBeginning(int val)
    {
        Node *newNode; //why isn't newNode = new Node implicit already in this line?
        newNode = new Node;
        newNode->data = val;
        if(!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    
        return;
    }
//	bool LinkedList::remove(int val);
//	void LinkedList::printForward() const;
//	void LinkedList::printBackward() const;
//};



