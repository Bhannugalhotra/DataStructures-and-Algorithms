#include<iostream>
using namespace std;

class twostacks
{
	int size;
	int capacity;
	int top1,top2;
	int *arr;

public:

	twostacks(int cap)
	{
		capacity = cap;
		size = 0;
		top1 = -1;
		top2 = capacity;
		arr = new int[capacity];
	}

	void push1(int data);
	void push2(int data);
	int pop1();
	int pop2();
	void print(int data);

};

void twostacks:: push1(int data)
{
	if(top1 + 1 == top2)
	{
		cout<<"stack overflow"<<endl;
		return;
	}
	
	arr[++top1] = data;
	size++;
}

void twostacks:: push2(int data)
{
	if(top2 - 1 == top1)
	{
		cout<<"stack overflow"<<endl;
		return;
	}
	
	arr[--top2] = data;
	size++;
}

int twostacks:: pop1()
{
	if(top1 < 0)
	{
		cout<<"stack underflow"<<endl;
		return 0;
	}
	
	int data = arr[top1--];
	return data; 
}

int twostacks:: pop2()
{
	if(top2 >= capacity)
	{
		cout<<"stack underflow"<<endl;
		return 0;
	}
	
	int data = arr[top2++];
	return data; 
}

void twostacks:: print(int data)
{
	cout<<data<<endl;
}

int main()
{
	twostacks s(100);

	return 0;
}


