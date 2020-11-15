#include<iostream>
using namespace std;

class node
{
	public:
		int key;
		int value;
		
		node(int a, int b) : key(a), value(b) {};
};


class unordered_map
{
	int table_size;
	int prime;
	int sze;
	node **a;
	
	public:
		
		unordered_map()
		{
			table_size = 101;
			prime = 97;
			sze = 0;
			
			a = new node*[table_size];
			
			for(int i = 0; i < table_size; i++)
			a[i] = NULL;
		}
		
		~unordered_map()
		{
			delete[] a;
		}
		int hash1(int key)
		{
			return (key + table_size) % table_size;
		}
		
		int hash2(int key)
		{
			return prime - (key + prime) % prime;
		}
		
		bool insert(int key,int value)
		{
			node *curr_node = new node(key, value);
			
			int idx1 = hash1(key);
			int idx2 = hash2(key);
			for(int i = 0; i < table_size; i++)
			{
				int curr_idx = (idx1 + i*idx2) % table_size;
				
				if(!a[curr_idx] || a[curr_idx] -> key == key)
				{
					if(a[curr_idx])
					delete(a[curr_idx]);
					
					a[curr_idx] = curr_node;
					sze++;
					return true;
				}
			}
			
			return false;
		}
		
		int find(int key)
		{
			int idx1 = hash1(key);
			int idx2 = hash2(key);
			for(int i = 0; i < table_size; i++)
			{
				int curr_idx = (idx1 + i*idx2) % table_size;
		
				if(!a[curr_idx])
				return -1;
				
				if(a[curr_idx] -> key == key)
				return a[curr_idx] -> value;
			}
			
			return -1;
		}
		
		void delete_node(int key)
		{
			int idx1 = hash1(key);
			int idx2 = hash2(key);
			for(int i = 0; i < table_size; i++)
			{
				int curr_idx = (idx1 + i*idx2) % table_size;
				
				if(!a[curr_idx])
				return;
				
				if(a[curr_idx] -> key == key)
				{
					delete(a[curr_idx]);
					a[curr_idx] = NULL;
					sze--;
					break;
				}
			}
		}
		
		bool empty()
		{
			return sze == 0;
		}
		
		int size()
		{
			return sze;
		}
		
		void display()
		{
			for(int i = 0; i < table_size; i++)
			if(a[i])
			cout<< a[i] -> key <<" "<<a[i] -> value<<endl;
		}
};

int main()
{
	unordered_map map;
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a>> b;
		map.insert(a,b);
	}
	
	map.display();
	
	return 0;
}
