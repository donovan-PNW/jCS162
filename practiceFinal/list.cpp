#include "list.h"

//put the implementation of your assigned functions here

int sumOfList(node *head)
{
    int sum;
    node *current;
    current = head;
    for(; current; current = current->next)
    {
        sum = sum + current->data;
    }
    
    return sum;
}

void insert(node *&head, int position, int newInt)
{
    node *current = NULL, *past = NULL, *newNode = NULL;
    int index = 0;
    //SHOULD THIS BE "IF HEAD == NULL?" DOES IT MATTER THAT HEAD ALREADY EXISTS BUT IS SET TO NULL?
    if(!head)
    {
        newNode = new node;
        newNode ->data = newInt;
        newNode ->next = NULL;
        head = newNode;
        return;
    }
    current = head;
    while(current != NULL)
    {
        if(current->next == NULL)
        {
            current->next = new node;
            current->data = newInt;
            current->next = NULL;
            std::cout << "Oops! Over bounds, I added it to the end\n\n";
            return;
        }
        else if(index == position)
        {
            std::cout << "Hi!\n";
            newNode = new node;
            newNode->data = newInt;
            newNode->next = current; 
            if(index == 0)
            {
                head = newNode;
            }
            else
            {
                past->next = newNode;
            }
            return;
        }
        else
        {
            past=current;
            current = current->next;
            std::cout << index;
            index++;
        }
    }
    return;
}
