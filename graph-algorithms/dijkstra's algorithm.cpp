typedef pair<int,int> data_type;
typedef priority_queue<data_type,vector<data_type>,greater<data_type>> min_pq;

int dijkstra(int src,int destination, vector<pair<int,int>> adj[],int V)
{
    vector<int> distance(V+1,INT_MAX);
    vector<bool> visited(V+1);
    
    min_pq pq;
    
    distance[src] = 0;
    
    pq.push({0,src});
    
    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();
        
        if(visited[u])
        continue;
        
        visited[u] = true;
        
        for(auto p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            
            if(distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                
                pq.push({distance[u],v});
            }
        }
    }
    
    return distance[destination];
}
