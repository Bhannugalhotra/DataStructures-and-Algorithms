#include<bits/stdc++.h>
using namespace std;
 
class graph_colouring
{
	int V,E;
	int m;
	vector<int> a;
	vector<int> *adj;
	bool finished;

public:
	graph_colouring()
	{
		cout<<"no of vertices and edges"<<endl;
		cin>> V >> E;

		adj = new vector<int>[V];
		a = vector<int>(V);

		for(int i = 0; i < E; i++)
		{
			int u,v;
			cin>>u>>v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cout<<"enter no. of colours :"<<endl;
	    cin >> m;

	    finished = false;
	}

	vector<int> construct_candidate(int k);
	void backtrack(int k);
	void colour_graph();
};

vector<int> graph_colouring:: construct_candidate(int k)
{
	vector<int> candidates;
	vector<bool> visited(m+1);

    for(auto i : adj[k])
    visited[a[i]] = true;
     	
    for(int i = 1; i <= m ;i++)
    if(visited[i] == false)
    candidates.push_back(i);

	return candidates;
}

void graph_colouring:: backtrack(int k)
{
	if(k == V)
	{
	 	finished = true;
	 	return;
	}

	vector<int> candidates = construct_candidate(k);
	
	for(auto i : candidates)
	{
		a[k] = i;
		backtrack(k+1);

		if(finished)
		return;
		
		a[k] = 0;
	}
}

void graph_colouring:: colour_graph()
{
	backtrack(0);	

	cout<<"colours of vertices"<<endl;

	for(int i = 0; i < V; i++)
 	cout<< i <<" "<< a[i] <<endl;
}


int main()
{
	graph_colouring sol;

	sol.colour_graph();
}
