
vector<vector<int>> floyd_warshall(vector<vector<int>> &graph)
{
    vector<vector<int>> ans = graph;

    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(i == j || i == k || j == k)
        continue;
        
        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
    }

    return ans;
}