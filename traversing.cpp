#include<iostream>
using namespace std;

struct Node
{
	int Data;
	Node * next ;
	
};

int main()
{
	Node*head = new Node();
	Node*second = new Node();
	
	
	head->Data = 10;
	head->next = second;
	
		head->Data = 20;
	head->next = NULL;
	Node* temp=head;
	
	while(temp != NULL)
	
	{
		cout<<temp->Data<<" ->";
		temp = temp ->next;
	}
	cout<<"NULL";
	return 0;
}
