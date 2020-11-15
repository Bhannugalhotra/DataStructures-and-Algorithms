class inf
{
    public:
    
    bool is_bst;
    int size, max, min;
    
    inf(bool a,int b,int c = INT_MIN,int d = INT_MAX):is_bst(a),size(b),max(c),min(d) {};
};

inf postorder(node *root,int &max_size)
{
    if(!root)
    return {true,0};
    
    inf left = postorder(root -> left, max_size);
    
    inf right = postorder(root -> right, max_size);
    
    if(!left.is_bst or !right.is_bst)
    return {false,0};
    
    if(root -> data <= left.max or root -> data >= right.min)
    return {false,0};
    
    inf curr{true, left.size + right.size + 1};
    
    curr.min = min(root -> data, left.min);
    curr.max = max(root -> data, right.max);
    
    max_size = max(max_size, curr.size);
    
    return curr;
}

int largestBst(node *root)
{
    if(!root) return 0;
    
    int max_size = 1;
    
    postorder(root, max_size);
    
    return max_size;
}