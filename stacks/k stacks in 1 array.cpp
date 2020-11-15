#include<iostream>
using namespace std;

class stack
{
	int m;
	int *arr;
	int *top,*base;
	int capacity;
	int size;
	
	public:
		
		stack(int k)
		{
			m = k;
			capacity = 25;
			size = 0; 
            arr = new int[capacity];
			base = new int[m];
			top = new int[m];
			
			for(int i=0; i < m; i++)
			base[i] = i *(capacity/m);
			
			for(int i=0; i < m; i++)
			top[i] = base[i] - 1;			
		}
		
		bool empty(int k)
		{
			return top[k] == base[k] - 1;
		}
		
		void push(int data,int k)
		{
			if(size == capacity)
			return;
			
			if(top[k] + 1 == base[k+1])
			shift(top[k],base[k]);
			
			arr[++top[k]] = data;
			size++;
		}
		
		int pop(int k)
		{
			if(empty(k))
			return -1;
			
			size--;
			return arr[top[k]--];
		}
		
		void shift(int tp,int bs)
		{
			int i = tp;
			while(i < m && top[i] + 1 == base[i+1])
			i++;
			
			if(i < m)
			{
				for(int j = i; j > tp; j++)
				arr[j + 1] = arr[j];
				
				
			}
			
			else
			{
				i = bs;
				while(i > 0 && top[i - 1] == top[i])
				i--;
				
				for(int j = i; j <= tp; j++)
				arr[j - 1] = arr[j];
				
				top[tp]--;
				base[bs]--;
			}
			
		}
	 
};

int main()
{
	stack s(5);
	
	for(int k = 0; k < 5; k++)
	{
		for(int i=0; i < 5; i++)
		s.push(i,k);
	}
	
	
	for(int i = 0; i < 5; i++)
	{
		 while(!s.empty(i))
		 cout<<s.pop(i)<<" ";
		 
		 cout<<endl;
	}
	
	 
}
