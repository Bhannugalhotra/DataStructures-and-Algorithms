#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int s,vector<bool> &visited,list<int> &l)
{
	if(visited[s])
	return;
	
	visited[s] = true;
	
	for(int i : adj[s])
	dfs(adj,i,visited,l);
	
	l.push_front(s);
}
list<int> topological_sort(vector<int> adj[],int V)
{
	vector<bool> visited(V);
	list<int> l;
	
	for(int i = 0; i < V; i++)
	dfs(adj,i,visited,l);
	
	return l;
}

int main()
{
	int V,E;
	cin>>V>>E;

	vector<int> adj[V];
	
	for(int i = 0; i < E; i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
	}
	
	list<int> l = topological_sort(adj,V);
	
	for(auto i : l)
	cout<<i<<" ";
}
