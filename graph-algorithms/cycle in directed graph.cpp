void dfs(int u, vector<int> adj[], vector<int> &visited, bool &is_cycle)
{
    visited[u] = 1;
    
    for(int v : adj[u])
    {
        if(visited[v] == 0)
        {
            dfs(v,adj,visited,is_cycle);
        }
        
        else if(visited[v] == 1)
        {
            is_cycle = true;
            return;
        }
    }
    
    visited[u] = 2;
}

int cycle_in_directed_graph(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V+1];
    
    for(vector<int> &v : edges)
    adj[v[0]].push_back(v[1]);
    
    vector<int> visited(V+1);
    
    bool is_cycle = false;
    
    for(int i = 1; i <= V; i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,is_cycle);
            
            if(is_cycle)
            return true;
        }
    }
    
    return is_cycle;
}
