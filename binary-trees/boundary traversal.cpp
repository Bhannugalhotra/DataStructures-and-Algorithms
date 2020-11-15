
vector<int> ans;

void left_boundary(node *root)
{
    if(!root) return;
    
    if(!root -> left and !root -> right)
    return;
    
    ans.push_back(root -> data);
    
    if(!root -> left)
    left_boundary(root -> right);
    
    else left_boundary(root -> left);
}

void right_boundary(node *root)
{
    if(!root) return;
    
    if(!root -> left and !root -> right)
    return;
    
    if(!root -> right)
    right_boundary(root -> left);
    
    else right_boundary(root -> right);
    
    ans.push_back(root -> data);
}

void leaf_nodes(node *root)
{
    if(!root) return;
    
    if(!root -> left and !root -> right)
    ans.push_back(root -> data);
    
    else
    {
        leaf_nodes(root -> left);
        leaf_nodes(root -> right);
    }
}
vector<int> printBoundary(node *root)
{
    if(!root)
    return {};
    
    ans.clear();
    
    ans.push_back(root -> data);
    
    left_boundary(root -> left);
    
    leaf_nodes(root -> left);
    leaf_nodes(root -> right);
    
    right_boundary(root -> right);
    
    return ans;
}