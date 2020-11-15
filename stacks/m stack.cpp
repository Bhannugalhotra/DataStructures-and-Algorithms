#include<bits/stdc++.h>
using namespace std;

class m_stacks
{
	int capacity, size;
	int m;
	
	vector<int> base, top ,arr;

public:

	m_stacks(int cap,int k)
	{
		capacity = cap;
		size = 0;
		m = k;
		base = vector<int>(m);
		top = vector<int>(m);
		arr = vector<int>(capacity);
		
		for(int i = 0; i < m ;i++)
		{
		    base[i] = i*(capacity/m);
		  	top[i] = base[i] - 1;
		}
	}

	bool full();
	void push(int k, int data);
	int pop(int k);
	bool right_shift(int stackno);
	bool left_shift(int stackno);
	void print(int data);
};

bool m_stacks:: full()
{
	return size == capacity;
}

void m_stacks:: push(int k, int data)
{
	if(full())
	{
		cout<<"stack overflow"<<endl;
		exit(1);
	}
	
	int stackno = k - 1;
	
	if(top[stackno] + 1 == base[stackno+1])
	{
		if(right_shift(stackno + 1));
		
		else
		left_shift(stackno);
	}
	
	arr[++top[stackno]] = data;
}

int m_stacks:: pop(int k)
{
	int stackno = k - 1;
	
	if(top[stackno] == base[stackno] - 1)
	{
		cout<<"stack underflow"<<endl;
		exit(1);
	}
	
	return arr[top[stackno]--];
}

bool m_stacks:: right_shift(int stackno)
{
	int i = stackno;
	
	while(i < m and top[i] + 1 == base[i+1])
	i++;
	
	if(i == m)
	return 0;  
	
	for(int j =  top[i] ; j >= base[stackno] ; j--)
	{
		arr[j+1] = arr[j];
	}
	
	for(int j = stackno; j <= i; j++)
	{
		base[j]++;
		top[j]++;
	}

	return 1;
}

bool m_stacks:: left_shift(int stackno)
{
	int i = stackno;
	
	while(i > 0 and base[i] - 1 == top[i-1])
	i--;
	
	if(i == 0)
	return 0;
	
	for(int j = base[i]; j > top[stackno] ; j++)
	{
		arr[j-1] = arr[j];
	}
	
	for(int j = i; j <= stackno ; j--)
	{
		base[j]--;
		top[j]--;
	}
	
	return 1;
}

void m_stacks:: print(int data)
{
	cout<<data<<endl;
}

int main()
{
	m_stacks s(100,10);
	
	return 0;
}
