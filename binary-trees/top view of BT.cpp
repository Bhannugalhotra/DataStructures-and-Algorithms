map<int,int> mp;

void preorder(node *root, int col)
{
    if(!root) return;
    
    if(!mp.count(col))
    mp[col] = root -> data;
    
    preorder(root -> left, col-1);
    preorder(root -> right, col+1);
}

// using preorder traversal
void topView1(node *root)
{
    mp.clear();
    
    preorder(root, 0);
    
    for(auto i : mp)
    cout<< i.second <<" ";
}

// using level order traversal
void topView2(node *root)
{
    mp.clear();
        
    queue<pair<node*,int>> q;
    q.push({root,0});
    
    while(!q.empty())
    {
        root = q.front().first;
        int col = q.front().second; q.pop();
        
        if(!mp.count(col))
        mp[col]= root -> data;
        
        if(root -> left)
        q.push({root -> left, col-1});
        
        if(root -> right)
        q.push({root -> right, col + 1});
    }
    
    for(auto i : mp)
    cout<< i.second <<" ";
}


