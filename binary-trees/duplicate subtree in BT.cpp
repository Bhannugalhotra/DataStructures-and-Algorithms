
unordered_set<string> st;

string is_subtree(node *root, bool &found)
{
    if(!root)
    return "$";
    
    string left = is_subtree(root -> left, found);
    string right = is_subtree(root -> right, found);
    
    string curr = root -> data + left + right;
    
    if(st.count(curr) && curr.size() > 3)
    found = true;
    
    st.insert(curr);
    
    return curr;
}

bool dupSub(node *root)
{
    st.clear();
    
    bool found = false;
    
    is_subtree(root, found);
    
    return found;
}