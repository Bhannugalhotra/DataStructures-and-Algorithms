
class Node
{
public:
    int val;
    vector<Node*> neighbors;
    
    Node(int _val = 0)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution
{
    unordered_map<Node*,Node*> seen;
public:
    
    Node* dfs(Node *root)
    {
        if(seen.count(root))
            return seen[root];
        
        Node *newnode = new Node(root -> val);
        
        seen[root] = newnode;
        for(Node* v : root -> neighbors)
            newnode -> neighbors.push_back(dfs(v));
        
        return newnode;
    }
    Node* cloneGraph(Node* node)
    {
        if(!node)
            return NULL;
        
        return dfs(node);
        
    }
};