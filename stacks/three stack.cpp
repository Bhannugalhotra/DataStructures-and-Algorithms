#include<iostream>
using namespace std;

class threestack
{
	int size3;
	int capacity;
	int top1,top2,top3,base;
	int *arr;

public:

	threestack(int cap)
	{
		size3 = 0;
		capacity = cap;
		top1 = -1;
		top2 = capacity;
		base = capacity/3;
		top3 = base - 1;
		arr = new int[capacity];
	}

	void push1(int data);
	void push2(int data);
	void push3(int data);
	int pop1();
	int pop2();
	int pop3();
	bool shift_middle_left();
	bool shift_middle_right();
	void print(int data);
};

void threestack:: push1(int data)
{
	if(top1 + 1 == base)
	{
		if(!shift_middle_right())
	    {
	    	cout<<"stack overflow"<<endl;
	    	return;
		}
	}
	
	arr[++top1] = data;
}

void threestack:: push2(int data)
{
	if(top2 - 1 == top3)
	{
		if(!shift_middle_left())
	    {
	    	cout<<"stack overflow"<<endl;
	    	return;
		}
	}
	
	arr[--top2] = data;
}

void threestack:: push3(int data)
{
	if(top3 + 1 == top2)
	{
		if(!shift_middle_left())
	    {
	    	cout<<"stack overflow"<<endl;
	    	return;
		}
	}
	
	arr[++top3] = data;
	size3++;
}

bool threestack:: shift_middle_left()
{
	if(base - 1 == top1)
	return 0;
	
	int i = size3;
	int j = base;
	
	while(i--)
	{
		arr[j - 1] = arr[j];
		j++;
	}
	base--;
	top3--;	
	
	return 1;
}

bool threestack:: shift_middle_right()
{
	if(top3 + 1 == top2)
	return 0;
	
	int i = size3;
	int j = top3;
	
	while(i--)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	base++;
	top3++;
	
	return 1;
}

int threestack:: pop1()
{
	if(top1 < 0)
	{
		cout<<"stack underflow"<<endl;
		return 0;
	}
	
	int data = arr[threestack:: top1--];
	
	return data;
}

int threestack:: pop2()
{
	if(top2 >= capacity)
	{
		cout<<"stack underflow"<<endl;
		return 0;
	}
	
	int data = arr[top2++];
	
	return data;
}

int threestack:: pop3()
{
	if(top3 < base)
	{
		cout<<"stack underflow"<<endl;
		return 0;
	}
	
	int data = arr[top3--];
	
	return data;
}

void threestack:: print(int data)
{
	cout<<data<<endl;
}

int main()
{
	threestack s(100);
	
	return 0;
}


