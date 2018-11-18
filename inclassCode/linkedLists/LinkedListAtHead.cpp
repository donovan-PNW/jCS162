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

//function prototypes
void addAtHead(Node *&head, Node *&tail, int num);
void printList(Node *head);
void printReverse(Node *head);

//main
int main()
{
	//declare pointers
	Node *head = NULL, *tail = NULL, *curr;
	int num = 0;
	cout << "Please enter numbers. (999 to quit):";
	cin >> num;
	//call the add function
	addAtHead(head, tail, num);
	//print the list
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
	return 0;
}	
	
void addAtHead(Node *&head, Node *&tail, int num)
{
	Node *newNode;
	while(num != SENTINEL)
    {
        newNode = new Node;
        newNode->data = num;
        newNode->next = NULL;
        //check to see if list is empty
        if(!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        cin >> num;
    }
}

//print the list
void printList(Node *head)
{
	Node *curr = head;
	for(; curr; curr = curr->next)
	{
		cout << curr->data << endl;
	}
	curr = NULL;
}

//print using recursion
void printReverse(Node *curr)
{
	if(curr)
	{
		printReverse(curr->next);
	}
	else
		return;
	cout << curr->data << endl;
}


