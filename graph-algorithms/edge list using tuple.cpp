#include<bits/stdc++.h>
using namespace std;

typedef vector<tuple<int,int,int>> vt;

void addedge(vt &edge, int u, int v,int w)
{
	edge.push_back(make_tuple(u,v,w));
}

void printgraph(vt edge)
{
	cout<<"edges of graph with weight are"<<endl;
	
	for(auto i : edge)
	{
		int u,v,w;
		tie(u,v,w) = i;
		cout<<u<<" "<<v<<" "<<w<<endl;
    }

}

int main()
{
	vt edge;
	
	int e;
	cout<<"no of edges"<<endl;
	cin>>e;
	for(int i =0 ; i< e; i++)
	{
		int u,v,w;
		cout<<"enter edge with weight"<<endl;
		cin>>u>>v>>w;
		addedge(edge,u,v,w);
	}
	
	
	
	printgraph(edge);
}
