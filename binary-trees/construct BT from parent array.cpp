

node* construct_tree_from_parent_array(vector<int> parent, int n)
{
    vector<node*> a;
    
    for(int i = 0; i < n; i++)
    a.push_back(new node(i));
    
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