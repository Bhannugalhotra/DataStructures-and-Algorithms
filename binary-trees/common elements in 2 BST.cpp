
vector<int> printCommon(node *root1, node *root2)
{
    vector<int> common_elements;
    stack<node*> s1,s2;
    
    while(true)
    {
        while(root1)
        {
            s1.push(root1);
            root1 = root1 -> left;
        }
        
        while(root2)
        {
            s2.push(root2);
            root2 = root2 -> left;
        }
        
        if(s1.empty() or s2.empty())
        break;
        
        root1 = s1.top();  
        root2 = s2.top();  
        
        if(root1 -> data == root2 -> data)
        {
            common_elements.push_back(root1 -> data);
            s1.pop();
            s2.pop();
            root1 = root1 -> right;
            root2 = root2 -> right;
        }
        
        else if(root1 -> data < root2 -> data)
        {
            root1 = root1 -> right;
            s1.pop();
            root2 = NULL;
        }
        
        else
        {
            root2 = root2 -> right;
            s2.pop();
            root1 = NULL;
        }
    }
    
    return common_elements;
}