#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;
typedef vector<ipair> vp;
typedef priority_queue<ipair,vector<ipair>,greater<ipair>> min_pq;

void prim(vp adj[],int s, int V)
{
	vector<int> parent(V,-1);
	vector<bool> inmst(V);
	vector<int> key(V,INT_MAX);
	
	min_pq pq;
	key[s] = 0;
	
	pq.push({0,s});
	
	while(!pq.empty())
	{
		int u =  pq.top().second; pq.pop();
		
		inmst[u] = true;
		
		for(auto i : adj[u])
		{
			int v = i.first;
			int w = i.second;
			
			if(inmst[v] == false && w < key[v])
			{
				key[v] = w;
				parent[v] = u;
				pq.push({key[v],v});
			}
		}			
	}

	cout<<"mst :"<<endl;

	for(int i = 0; i < V; i++)
		cout<<i<<" "<<parent[i]<<endl;
}


int main()
{
	int V,e;
	cout<<"no of vertices"<<endl;
	cin>>V;
	cout<<"no of edges"<<endl;
	cin>>e;
	
	vp adj[V];
	
	for(int i =0 ;i< e;i++)
	{
		int u,v,w;
		cout<<"enter edge"<<endl;
		cin>>u>>v>>w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	cout<<"enter source vertex"<<endl;
	int s;
	cin>>s;
	
	prim(adj,s,V);
	
	return 0;
}
