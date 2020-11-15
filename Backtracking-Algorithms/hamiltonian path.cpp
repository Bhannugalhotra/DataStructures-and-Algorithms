
class solution
{
    int V,E;
    vector<int> *adj;
    vector<bool> visited;
    public:
    
    solution()
    {
        cin >> V >> E;
     
        adj = new vector<int>[V+1];

        for(int i = 0;i < E; i++)
        {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        visited = vector<bool>(V+1);
    }
    
    bool backtrack(int u, int count)
    {
        if(count + 1 == V)
        return true;
        
        visited[u] = true;
        
        int ans = false;
        
        for(int v : adj[u])
        if(!visited[v])
        ans = ans or backtrack(v, count + 1);
        
        visited[u] = false;
        
        return ans;
    }
    void hamiltonian_path()
    {
        bool ans = false;
        
        for(int i = 1; i <= V; i++)
        ans = ans or backtrack(i,0);
        
        cout<< ans << endl;
    }
};