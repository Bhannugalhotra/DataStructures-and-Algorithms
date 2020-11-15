class inf
{
    public:
    int data;
    int depth;
    
    inf(int a,int b) : data(a), depth(b) {};
};

map<int,inf> mp;

void preorder(node *root, int col, int depth)
{
    if(!root) return;
    
    inf curr (root -> data, depth);
    
    if(!mp.count(col))
    mp.insert({col,curr});
    
    else if(mp.at(col).depth <= depth)
    mp.at(col) = curr;
    
    preorder(root -> left, col-1, depth+1);
    
    preorder(root -> right, col+1, depth+1);
}
vector<int> bottomView(node *root)
{
    mp.clear();
   
    preorder(root, 0, 0);
   
    vector<int> ans;
   
    for(auto i : mp)
    ans.push_back(i.second.data);
   
    return ans;
}
