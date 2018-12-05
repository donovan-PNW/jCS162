#include "list.h"

//put the implementation of your assigned functions here

int sumOfList(node *head)
{
    int sum;
    node *current;
    current = head;
    for(; current; current = current->next)
    {
       // std::cout << current->data;
        sum = sum + current->data;
    }
    
    return sum;
}
//TRY RETOOLING THIS TO MAKE IT A PRESENT AND A PAST POINTER, SO THAT PRESENT POINTER STARTS AT ZERO AND MOVES FORWARD (PAST = PRES, PRES = PRES->NEXT)
void insert(node *&head, int position, int newInt)
{
    node *current = NULL, *future = NULL, *newNode = NULL;
    int index = 0;
    //SHOULD THIS BE "IF HEAD == NULL?" DOES IT MATTER THAT HEAD ALREADY EXISTS BUT IS SET TO NULL?
    if(!head)
    {
        current = new node;
        current ->data = newInt;
        current ->next = NULL;
        return;
    }
    current = head;
    future = head->next;
    while(index < position)    //for(index = 0; position >= index; index++)
    {
        if(future == NULL)
        {
            future = new node;
            future->data = newInt;
            future->next = NULL;
            std::cout << "Oops! Over bounds, I added it to the end\n\n";
            return;
        }
        current = current->next;
        future = current->next;
        std::cout << index;
        index++;

        //else if(index == position)
        //{
        //    newNode = new node;
        //    newNode->data = newInt;
        //    current->next = newNode;
        //    newNode->next = future;
        //    return;
        //}
        //else
        //{
        //    current = current->next;
        //    future = current->next;
        //}
    }
    newNode = new node;
    newNode->data = newInt;
    current->next = newNode;
    newNode->next = future;
    return;
}
