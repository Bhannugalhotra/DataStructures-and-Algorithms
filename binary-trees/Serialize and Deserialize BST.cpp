
string serialize(node* root) 
{
    if(!root) return "";
    
    return to_string(root -> data) + "," + serialize(root -> left) + serialize(root->right);
}

node* build_tree(string &s,int &i,int max_val,int min_val)
{
    if(i == s.size()) return NULL;
    
    int pos = s.find(',' , i);
    int num = stoi(s.substr(i,pos));
    
    if(num <= min_val || num >= max_val)
        return NULL;
    
    i = pos + 1;
    node *root = new node(num);
    
    root -> left = build_tree(s, i, root -> val, min_val);
    
    root -> right = build_tree(s, i, max_val, root -> val);
    
    return root;
}

node* deserialize(string data) 
{
    int i = 0;
    
    return build_tree(data,i,INT_MAX, INT_MIN);
}
