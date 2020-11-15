
node* build(vector<int> &post,int &i,int l,int r,unordered_map<int,int> &map)
{
    if(i == post.size() or l > r)
    return NULL;
    
    Node *root = new node(post[i++]);
    
    if(l == r)
    return root;
    
    int s = map[root -> data];
    
    root -> right = build(post,i,s+1,r,map);
    root -> left = build(post,i,l,s-1,map);
    
    return root;
}

node* construct_tree_from_inorder_and_postorder(vector<int> &in, vector<int> &post, int n)
{
    unordered_map<int,int> map;
    
    for(int i = 0; i < n; i++)
    map[in[i]] = i;

    reverse(begin(post),end(post));

    int i = 0;
    return build(post,i,0,n-1,map);
}
