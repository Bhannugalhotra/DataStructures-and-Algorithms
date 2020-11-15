#include<bits/stdc++.h>
using namespace std;

typedef vector<tuple<int,int,int>> vt;

bool bellman_ford(vt &edge,int s,int V)
{
	vector<int> distance(V,INT_MAX);
	
	distance[s] = 0;
	
	for(int i = 1; i <= V-1; i++)
	{
		for(auto e : edge)
		{
			int u,v,w;
			tie(u,v,w) = e;
			
			if(distance[u] != INT_MAX)
			distance[v] = min(distance[v], distance[u] + w);
		}
	}
	
	bool negative_cycle = false;
	
	for(auto e : edge)
	{
		int u,v,w;
		tie(u,v,w) = e;
		if(distance[v] > distance[u] + w)
		{
			negative_cycle = true;
			break;
		}
	}

	if(negative_cycle)
	{
		cout<<"graph contain negetive cycle"<<endl;
		return false;
	}
	
	cout<<"shortes distance from "<<s<<" :"<<endl;

	for(int i = 0; i< V; i++)
	cout<<i<<"  "<<distance[i]<<endl;
	
	return negative_cycle;
	
}



int main()
{
	int V,e;
	cout<<"no of vertices"<<endl;
	cin>>V;
	cout<<"no of edges"<<endl;
	cin>>e;
	
	vt edge;
	
	for(int i = 0 ; i < e; i++)
	{
		int u,v,w;
		cout<<"enter edge with weight"<<endl;
		cin>>u>>v>>w;
		edge.push_back(make_tuple(u,v,w));
		edge.push_back(make_tuple(v,u,w));
	}
	
	cout<<"enter source vertex"<<endl;
	int s = 1;
	//cin>>s;
	
	int is_negative_cycle = bellman_ford(edge,s,V);
	cout<<is_negative_cycle<<endl;
	
	return 0;
}

