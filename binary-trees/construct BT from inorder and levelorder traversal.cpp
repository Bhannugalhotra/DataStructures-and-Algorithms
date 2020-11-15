
node* construct_tree_from_inorder_and_levelorder(vector<int> in, vector<int> level,int n)
{
    vector<bool> visited(n);
    unordered_map<int,int> inorder;
    
    for(int i = 0; i < n; i++)
    inorder[in[i]] = i;
    
    int i = 0;
    node *tree = new node(level[i++]);

    queue<node*> q;
    q.push(tree);
    
    while(!q.empty() and i < n)
    {
        node *root = q.front();  q.pop();

        int idx = inorder[root -> key];
        visited[idx] = true;
        
        if(idx > 0 and !visited[idx-1])
        {
            root -> left = new node(level[i++]);
            q.push(root -> left);
        }
        
        if(i < n and idx < n-1 and !visited[idx+1])
        {
            root -> right = new node(level[i++]);
            q.push(root -> right);
        }
    }
    
    return tree;
}
Node *createTree(int parent[], int n)
{
    vector<Node*> a;
    
    for(int i = 0; i < n; i++)
    a.push_back(new Node(i));
    
    int root;
    for(int i = 0; i < n; i++)
    {
        if(parent[i] == -1)
        root = i;
        
        else
        {
            if(!a[parent[i]] -> left)
            a[parent[i]] -> left = a[i];
            
            else if(!a[parent[i]] -> right)
            a[parent[i]] -> right = a[i];
        }
    }
   
    return a[root];
}