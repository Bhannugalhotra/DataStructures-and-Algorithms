
class node
{
public:
    int data;
    node *left, *right, *random;

    node(int x) : data(x) , left(NULL), right(NULL), random(NULL) {};
};

unordered_map<node*,node*> mp;

node* clone(node *root)
{
    if(!root)
    return nullptr;
    
    if(mp.count(root))
    return mp[root];
    
    node *cloned_root = new Node(root -> data);
    mp[root] = cloned_root;
    
    cloned_root -> left = clone(root -> left);
    cloned_root -> right = clone(root -> right);
    
    cloned_root -> random = clone(root -> random);
    
    return cloned_root;
}

node* cloneTree(node* root)
{
   mp.clear();
   
   return clone(root);
}
