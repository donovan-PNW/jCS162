//This program will build a list of integers using linear linked lists
#include <iostream>
using namespace std;

//struct for Node
struct Node
{
	int data;
	Node *next;
};

//constants
const int SENTINEL = 999;

void printReverse(Node *head);

//main
int main()
{
	//declare pointers
	Node *head = NULL, *tail = NULL, *newNode = NULL, *curr = NULL, *prev = NULL;
	int num = 0;
	//allocate memory for newNode and populate it
	cout << "Please enter numbers. (999 to quit):";
	cin >> num;
	while(num != SENTINEL)
	{
		newNode = new Node;
		newNode->data = num;
		newNode->next = NULL;
		prev = NULL;
		//check to see if list is empty
		if(!head)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			curr = head;
			while(curr && curr->data < newNode->data)
			{
				prev = curr;
				curr = curr->next;
			}
			//check to see if we are at the end of our list
			if(!curr)
			{
				tail->next = newNode;
				tail = newNode;
			}
			//insert in between
			else if(prev)
			{
				newNode->next = curr;
				prev->next = newNode;
			}
			//insert at the beginning
			else if(!prev)
			{
				newNode->next = curr;
				head = newNode;
			}
			else
			{
				cout << "No idea why I would be here!" << endl;
			}
		}
		cin >> num;
	}
	/*print the list
	for(curr = head; curr; curr = curr->next)
	{
		cout << curr->data << endl;
	}*/
	printReverse(head);
	//delete all memory for the list
	curr = head;
	while(curr)
	{
		curr = curr->next;
		delete head;
		head = curr;
	}
	head = NULL;
	tail = NULL;
	curr = NULL;
	prev = NULL;

	return 0;
}	
	
//print using recursion
void printReverse(Node *curr)
{
    if(!curr)
    {
        return;
    }
    printReverse(curr->next);
    cout << curr->data << endl;
}

