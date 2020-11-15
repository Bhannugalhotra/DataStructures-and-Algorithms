
node* generate_tree(vector<int> &pre,unordered_map<int,int> &map,int &i,int l,int r)
{
    if(i == pre.size() or l > r)
    return NULL;
    
    node *root = new Node(pre[i++]);
    
    if(left == right)
    return root;
    
    int s = map[root -> data];
    
    root -> left = generate_tree(pre,map,i,l,s-1);
    root -> right = generate_tree(pre,map,i,s+1,r);
    
    return root;
}
node* construct_tree_from_inorder_and_preorder(vector<int> &in,vector<int> &pre)
{ 
    int n = pre.size();
    unordered_map<int,int> map;
    
    for(int i = 0; i < n; i++)
    map[in[i]] = i;
    
    int i = 0;
    return generate_tree(pre,map,i,0,n-1);
}