#include "list.h"
int sumOfList(node * head)
{
    int sum = 0;
    node *current;//, *prev;
    //prev = new node;
    current = head;
    while(current)
    {
        sum += current->data;
        current = current->next;
    }
    delete current;
    return sum;
}



void insert(node *& head, int position, int newInt)
{
    node *current, *prev, *newNode;
    newNode = new node;
    newNode ->data = newInt;
    newNode ->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        current = head;
        prev = NULL;
        int count = 0;
        while(count < position)
        {
            if(current->next == NULL)
            {
                current->next = newNode;
                newNode->next = NULL;
                return;
            }
            prev = current;
            current = current->next;
            count++;
        }
        std::cout << count;
        std::cout << "\n"; 
        prev ->next = newNode;
        newNode ->next = current;
        //TRY ADDING THIS IN LATER
        //delete prev;
        return;

    }
    


    return;
}


void remove(node *& head, int position)
{
    int count = 0;
    node *current, *prev;
    if(!head)
    {
        std::cout << "NO HEAD!\n";
        return;
    }
    current = head;
    if(position == 0)
    {
        head = head->next;
        delete current;
        return;
    }
    while(current) 
    {
        if(current ->next == NULL)
        {
            std::cout << "BEYOND LIST SIZE!!\n";
            return;
        }
        else if(count == position)
        {
            
            prev->next = current->next;
            delete current;
            return;
        }
        else
        { 
            prev = current;
            current = current ->next;
            count++;
            std::cout << count;
        }
    }
    return;

    

    return;
}






















//put the implementation of your assigned functions here
