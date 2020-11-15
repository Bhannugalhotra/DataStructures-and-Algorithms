#include<bits/stdc++.h>
using namespace std;

class max_heap
{
	vector<int> a;
	
	public:
		
		int top()
		{
			if(a.size() == 0)
			return -1;
			
			return a.front();
		}
		
		void pop()
		{
			if(a.size() == 0)
			return;
			
			a[0] = a.back();
			a.pop_back();
			
			max_heapify(0);
		}
		
		void max_heapify(int i)
		{
			int l = 2*i + 1;
			int r = 2*i + 2;
			int largest = i;
			
			if(l < a.size() && a[l] > a[largest])
			largest = l;
			
			if(r < a.size() && a[r] > a[largest])
			largest = r;
			
			if(largest == i)
			return;
			
			int temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			
			return max_heapify(largest);
		}
		
		int parent(int i)
		{
			return (i - 1) / 2;
		}
		
		void push(int data)
		{
			a.push_back(data);
			int curr_index = a.size() - 1;
			
			while(curr_index > 0 && data > a[parent(curr_index)])
			{
				a[curr_index] = a[parent(curr_index)];
				curr_index = parent(curr_index);
			}
			
			a[curr_index] = data;
		}
		
		bool empty()
		{
			return a.size() == 0;
		}		
};

int main()
{
	int n;
	cin >> n;
	
	max_heap pq;
	
	for(int i = 0; i < n; i++)
	{
		int data;  cin >> data;
		pq.push(data);
	}
	
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
