#include<iostream>
using namespace std;

class node 
{
public:

	int data;
	node* next;
	node* prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}


	void inserattail(node*& head, node*& tail, int d)
	{
		node* temp = new node(d);
		
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		tail->next = head;
		head->prev = tail;
	}

	

	void display(node*& head)
	{
		node* temp = head;
		do
		{
			cout << temp->data << "->";
			temp = temp->next;
		} while (temp != head);

		cout << "(head)";
	}
};

void main()
{
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);
	node* node4 = new node(4);

	node* head = node1;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	node* tail = node4;
	

	node1->inserattail(head, tail, 5);
	node1->display(head);
	cout << endl;

	cout << endl;
}