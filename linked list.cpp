#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	node *next;
};
bool isEmpty(node *head);
int menu();
void insertAsFirstElement(node *&head,node *&last,int data);
void insert(node *&head, node *&last, int data);
void remove(node *&head, node *&last);
void showlist(node *current);
void update(node *&head, node *&current);

bool isEmpty(node *head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
int menu()
{
	int choice;
	cout << "Menu:- "<<endl;
	cout << "1)Insert data "<<endl;
	cout << "2)Remove data "<<endl;
	cout << "3)Display data "<<endl;
	cout << "4)Update data "<<endl;
	cout << "5)Exit Program " << endl;
	cin >> choice;
	cout << endl;
	return choice;


}
void insertAsFirstElement(node *&head, node *&last, int data)
{
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	head = temp;
	last = temp;
}
void insert(node *&head, node *&last, int data)
{
	if (isEmpty(head))
	{
		insertAsFirstElement(head,last,data);
	}
	else
	{
		node *temp = new node();
		temp->data = data;
		temp->next = NULL;
		last->next = temp;
		last = temp; 
	}
}
void remove(node *&head, node *&last)
{
	if (isEmpty(head))
	{
		cout << "The List Is Already Empty!" << endl; 
	}
	else
		if (head == last)
		{
			delete head;
			head = NULL;
			last = NULL;
		}
		else
		{	
			node *temp = head;
			head = head->next;
			delete temp;
		}

}
void showlist(node *current)
{
	if (isEmpty(current))
	{
		cout << "The List Is Empty!" << endl;
	}
	else
	{
		cout << "The List Contains:- " << endl;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

}

void update(node *&head, node *&current)
{
	int pos = 1;
	int Old, New;
	cout << "Enter The Old Node :- ";
	cin >> Old;
	cout << "Enter The New Node You Want To Update:- ";
	cin >> New;
	if (head == NULL)
	{
		cout << "Linked List Not Initialized!" << endl;
		return;
	}
	current = head;
	while (current->next != NULL)
	{
		if (current->data == Old)
		{
			current->data = New;
			cout << Old << " Node found at Position " << pos << endl;
			cout << "Updated Node is :- " << New << endl;
			return;
		}
		current = current->next;
		++pos;
	}


}
int main()
{
	node *head = NULL;
	node *last = NULL;
	node *current = head;
	int choice,data;
	do
	{
		choice = menu();
		switch (choice)
		{
			case 1:
			{
				cout << "Enter A Number:- ";
				cin >> data;
				insert(head, last, data);
				break;
			}
			case 2:
			{
				remove(head,last);
				break;
			}
			case 3:
			{
				showlist(head);
				break;
			}
			case 4:
			{
				update(head, current);
				break;
			}
			case 5:
			{
				exit(0);
				break;
			}
			default:
			{
				cout << "Sorry you entered Wrong Choice!" << endl;
			}

		}

	} while (choice!= 6);

	_getch();
	return 0;
}
/*
Follow me on my github ID https://github.com/Junaid-byte
Credits:-Junaid Jawed
*/