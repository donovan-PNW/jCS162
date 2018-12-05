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
    while(current != NULL)    //for(index = 0; position >= index; index++)
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
                return;
            }
            past->next = newNode;
            return;
        }
        past=current;
        current = current->next;
        std::cout << index;
        index++;
        //}

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
        //std::cout << index;
        //index++;
    }
    //newNode = new node;
    //newNode->data = newInt;
    //newNode->next = current->next; 
   // past->next = current;
    return;
}
