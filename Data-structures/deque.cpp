#include<iostream>
using namespace std;


class node
{
public:

	int data;
	node *next, *prev;
	
	node(int x) : data(x), next(NULL), prev(NULL) {};
};

class deque
{
	public:
		
	node *front;
	node *rear;
	
	deque()
	{
		front = rear = NULL;
	}
	
	bool empty();
	void insertRear(int data);
	void insertFront(int data);
	void deleteFront();
	int getFront();
	void deleteRear();
	int getRear();
	
};

bool deque::empty()
{
	return front == NULL; 
}

void deque::insertRear(int data)
{
	node *newnode = new node(data);
	
	if(empty())
	{
		front = rear = newnode;
		return; 
	}
	
	newnode -> prev = rear;
	rear -> next = newnode;
	rear = newnode;	
}

void deque::insertFront(int data)
{
	node *newnode = new node(data);
	
	if(empty())
	{
		front = rear = newnode;
		return; 
	}
	
	newnode -> next = front;
	front -> prev = newnode;
	front = newnode;
}

void deque::deleteFront()
{
	if(empty())
	{
		cout<<-1<<endl;
		return;
	}
	
	node *temp = front;
	front = front -> next;
	
	if(front)
	front -> prev = NULL;
	
	else
	rear = NULL;

	delete(temp);
}

int deque::getFront()
{
	
	if(empty())
	return -1;
	
	return front -> data;
}

void deque::deleteRear()
{
	if(empty())
	{
		cout<<-1<<endl;
		return;
	}
		
	node *temp = rear;
	rear = rear -> prev;
	
	if(rear)
	rear -> next = NULL;
	
	else
	front = NULL;
	
	delete(temp); 
}

int deque::getRear()
{
	
	if(empty())
	return -1;
	
	return rear -> data;
}

void print(int data)
{
	cout<<data<<endl;
}

int main()
{
	deque q;
	q.insertFront(5);
	cout<<q.getFront()<<endl;
}
