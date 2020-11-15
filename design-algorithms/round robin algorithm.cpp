#include<bits/stdc++.h>
using namespace std;

typedef priority_queue<node,vector<node>,compare> min_pq;

struct node
{
    int id;
    int arival_time;
    int exec_time;
    int index;
    node(int a,int b,int c,int d)
    {
       id = a;
       arival_time = b;
       exec_time = c;
       index = d;
    }
};

class compare
{
	public:
	bool operator()(const node &a,const node &b)
	{
		if(a.arival_time == b.arival_time)
		return a.index > b.index;
		
		return a.arival_time > b.arival_time;
	}
};

struct scnode
{
	int rem_time;
	int id;
	
	scnode *next;
	
	scnode(int a,int b)
	{
		id = a;
		rem_time = b;
		next = NULL;
	}
};

class scll
{
	public:
	scnode *dummy;
	scnode *head;
	scnode *tail;
	scnode *exec_ptr;
	int size;
	scll()
	{
		dummy = new scnode(0,0);
		head = dummy;
		tail = dummy;
		dummy -> next = dummy;
		exec_ptr = dummy;
		size = 0;
	}
	
	void insert(node data)
	{
		scnode *newnode = new scnode(data.id,data.exec_time);
        
		newnode -> next = head;
		tail -> next = newnode;
		tail = newnode;
		
		size++;
	}
	
	void delete_node(scnode *ptr)
	{
		scnode *temp = ptr -> next;
		ptr -> next = ptr -> next -> next;
		
		if(temp == tail)
		tail = ptr;
		
		delete(temp);
		
		size--;
	}
	
	void print_list()
	{
		cout<<"list : ";
		for(scnode *itr = head -> next; itr != dummy; itr = itr -> next)
		cout<<itr -> id<<" ";
		
		cout<<endl;	
	}
	vector<int> round_robin(min_pq &pq);
};

vector<int> scll::round_robin(min_pq &pq)
{
	vector<int> result;
	result.reserve(1000);
	
	int time = 0;
	
	while(!pq.empty() || size != 0)
	{
		while(!pq.empty() && pq.top().arival_time == time)
		{
			insert(pq.top());
			pq.pop();
		}
		
		time++;
		if(size == 0)
		continue;
		
		if(exec_ptr -> next == dummy)
		exec_ptr = exec_ptr -> next;
	    
		scnode *curr_ptr = exec_ptr -> next;
		result.emplace_back(curr_ptr -> id);
		
		curr_ptr -> rem_time--;
		
		if(curr_ptr -> rem_time == 0)
		delete_node(exec_ptr);
		
		else
		exec_ptr = exec_ptr -> next;

	}	
	
	return result;
}
int main()
{
    int n;
    cin >> n;
     
    vector<node> ll;
    
    for(int i = 0; i < n; i++)
    {
    	int a,b,c;
    	cin >> a >> b >> c;
    	
    	node newnode(a,b,c,i);
    	ll.emplace_back(newnode);
	}
	
    min_pq pq {begin(ll), end(ll)};
    
	scll cl;
	vector<int> result = cl.round_robin(pq);
	
	for(int i : result)
	cout<<i<<" ";
	
	cout<<endl;
	
	return 0;
}
