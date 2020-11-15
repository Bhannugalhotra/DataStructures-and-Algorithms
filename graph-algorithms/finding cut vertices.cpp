class cut_vertices_finder
{
	vector<int> num, low, parent;
	int time;
	
	public:
		
	cut_vertices_finder(int n) : time(1), num(n+1, -1) , low(n+1), parent(n+1,-1) {};
	
	void cut_vertices(vector<int> adj[],int u)
	{
		low[u] = num[u] = ++time;
		
		int children = 0;
		for(int v : adj[u])
		{
			if(num[v] == -1)
			{
				children++;
				parent[v] = u;
				cut_vertices(adj,v);
				
				low[u] = min(low[u],low[v]);
				
				if( parent[u] != -1 && low[v] >= num[u])
				cout<<"cut vertex : "<<u << endl;
			}
			
			else if(v != parent[u])
			low[u] = min(low[u],num[v]);
		}
		
		if(parent[u] == -1 && children > 1)
		cout<<"cut root : "<<u<<endl;
	}
	
	void cut_vertices(vector<int> adj[])
	{
		cut_vertices(adj,1);	
	}
};