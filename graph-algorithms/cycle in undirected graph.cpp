
void dfs(int u,int parent, vector<int> adj[], vector<bool> &visited, bool &is_cycle)
{
    visited[u] = true;
    
    for(int v : adj[u])
    {
        if(!visited[v] )
        {
            dfs(v,u,adj,visited,is_cycle);
        }
        
        else if(v != parent)
        {
            is_cycle = true;
            return;
        }
    }
}
 
int cycle_in_undirected_graph(int V, vector<vector<int> > &edges)
{
    vector<int> adj[V+1];
    
    for(vector<int> &v : edges)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(V+1);
    
    bool is_cycle = false;
    
    for(int i = 1; i <= V; i++)
    {
        if(!visited[i])
        {
            dfs(i,-1,adj,visited,is_cycle);
            
            if(is_cycle)
            return true;
        }
    }
    
    return is_cycle;
}