
void dfs_util(vector<int> adj[],int u,vector<bool> &visited,stack<int> &s)
{
	visited[u] = true;
	
	for(auto v : adj[u])
	if(!visited[v])
	dfs_util(adj,v,visited,s);
	
	s.push(u);
}

void transpose(vector<int> adj[],int V,vector<int> trans[])
{
	for(int u = 0; u < V; u++)
	{
		for(int v : adj[u])
		trans[v].push_back(u);
	}	
}

void dfs_util2(vector<int> adj[],int u,vector<bool> &visited)
{
	visited[u] = 1;
	
	cout<< u <<" ";
	for(int v : adj[u])
	if(!visited[v])
	dfs_util2(adj,v,visited);
}

int strongly_connected_components(vector<int> adj[],int V)
{
	vector<bool> visited(V);
	stack<int> s;
	
	for(int i = 0; i < V; i++)
	if(!visited[i])
	dfs_util(adj,i,visited,s);
	
	vector<int> trans[V];
	
	transpose(adj,V,trans);
	
	for(int i = 0; i < V; i++)
	visited[i] = false;
	
	int no_of_components = 0;
	while(!s.empty())
	{
		int u = s.top();  s.pop();
		
		if(!visited[u]){
			no_of_components++;
			dfs_util2(trans,u,visited);
		}
		cout<<endl;
	}

	return no_of_components;
}
