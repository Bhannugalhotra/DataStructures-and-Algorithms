
void rightView(node *root)
{
    if(!root) return;
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        root = q.front(); q.pop();
        
        if(!root)
        {
            if(!q.empty())
            q.push(NULL);
            
            continue;
        }
        
        if(q.empty() or !q.front())
        cout<< root -> data<<" ";
        
        if(root -> left)
        q.push(root -> left);
        
        if(root -> right)
        q.push(root -> right);
    }
}

