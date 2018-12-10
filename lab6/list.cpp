#include "list.h"
//put your implementation of LinkedList class here

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}
//LOOK AT ME!!!!!! YOU NEED TO CHANGE THIS SO IT ALWAYS ADDS AT START OF LIST!!
bool LinkedList::addAtBeginning(int val)
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
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        
        
       // tail->next = newNode;
       // newNode->prev = tail;
       // tail = newNode;
    }

    return true;
}
void LinkedList::printForward() const
{
    Node *current = head;
    for(; current; current = current->next)
    {
        cout << current->data << endl;
    }
    return;
}
	void LinkedList::printBackward() const
{
    Node *current = tail;
    for(; current; current = current ->prev)
    {
        cout << current->data << endl;
    }
    return;
}


bool LinkedList::remove(int val)
{

    Node *current = head;
    Node *upNext = current->next;
    Node *flag;
    if(head->data == val)
    {
        head = upNext;
        delete current;
        upNext->prev = NULL;
    }
    else
    {
        while(upNext != NULL)

        {
            if(val == (upNext->data))
            {
                flag = upNext;
                current->next = upNext->next;
                if(flag->next !=NULL)
                {
                    current = upNext->next;
                    current->prev = flag->prev;
                }
                else
                {
                    tail = current;
                }
                delete flag;


                return true;
            }

            current = current ->next;
            upNext = current ->next;
        }
    }


    return false;
}



















