#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;

void dfs(vp adj[],int u,vector<bool> &visited, stack<int> &stack)
{
	visited[u] = true;
	
	for(auto i : adj[u])
	{
		int v = i.first;
		
		if(visited[v] == false)
		dfs(adj,v,visited,stack);
	}
	stack.push(u);
}

stack<int> topological_sort(vp adj[], int V)
{
	stack<int> st;
	vector<bool> visited(V);

	for(int i = 0; i< V; i++)
	{
		if(visited[i] == false)
		dfs(adj,i,visited,st);
	}

	return st;
}

void dag_shortest_path(vp adj[],int s,int V)
{
    vector<unsigned int> distance(V,INT_MAX);
	
    distance[s] = 0;
    
    stack<int> stack = topological_sort(adj,V);
    
    while(!stack.empty())
    {
    	int x = stack.top();  stack.pop();
    	
    	for(pair<int,int> u : adj[x])
    	{
    	    int v,w;
    		v = u.first;
    		w = u.second;
    		
    		distance[v] = min(distance[v], distance[x] + w);
		}
    }
	
	cout<<"shortest distance is :"<<endl;
	for(int i = 0; i < V; i++)
		cout<< i <<" "<< distance[i] <<endl;
}

int main()
{
	int V,e;
	cout<<"no of vertices"<<endl;
	cin>>V;
	cout<<"no of edges"<<endl;
	cin>>e;
	
	vp adj[V];
	
	for(int i =0; i<e; i++)
	{
		int u,v,w;
		cout<<"enter edge with weight"<<endl;
		cin>>u>>v>>w;
		
		adj[u].push_back({v,w});
	}
	
	int s;
	cout<<"enter source vertex"<<endl;
	cin>>s;
	
	
	dag_shortest_path(adj,s,V);
	
	return 0;
}
