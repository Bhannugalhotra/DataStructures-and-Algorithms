 
string serialize(node* root) 
{
    if(!root)
    return "$";
    
    return to_string(root -> data) + "," + serialize(root -> left) + "," + serialize(root -> right);
    
}

node* build_tree(stringstream &s)
{
    string curr;
    getline(s, curr, ',');
    
    if(curr == "$")
        return nullptr;
   
    node *root = new node(stoi(curr));
  
    root -> left = build_tree(s);
    
    root -> right = build_tree(s);

    return root;
}


node* deserialize(string data) 
{
    stringstream s(data);
    return build_tree(s);
}
