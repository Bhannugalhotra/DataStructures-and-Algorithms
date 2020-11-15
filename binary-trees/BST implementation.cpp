class node
{
public:
	int data;
	node *left, *right;

	node(int x) : data(x) , left(NULL), right(NULL) {};
};

class bst
{
public:
	node *root;
	int size;
	
	bst() : root(NULL), size(0) {};
	
	node* insert(node *root,int data);
	void insert(int data);
	node* deletenode(node *root,int data);
	void deletenode(int data);
	bool search(node *root,int data);
	void inorder();
};

// max node in bst
node* max(node *root)
{
	if(!root -> right)
	return root;
	
	return max(root -> right);
}

// min node in bst
node* min(node *root)
{
	if(!root -> left)
	return root;
	
	return min(root -> left);
}

node* bst::insert(node *root,int data)
{

	if(!root)
	root = new node(data);
	
	else if(root -> data < data)
	root -> right = insert(root -> right,data);
	
	else
	root -> left = insert(root -> left,data);

	return root;
}

void bst::insert(int data)
{
	this -> root = insert(this -> root,data);
}

node* bst::deletenode(node *root,int data)
{
	if(!root)
	return root;
	
	if(root -> data > data)
	root -> left = deletenode(root -> left,data);
	
	else if(root -> data < data)
	root -> right = deletenode(root -> right,data);
	
	else
	{
		if(root -> left && root -> right)
		{
			node *succ = min(root -> right);
			root -> data = succ -> data;
			root -> right = deletenode(root -> right,succ -> data);
		}
		
		else if(root -> left)
		{
			node *temp = root;
			root = root -> left;
			delete(temp);
		}
		
		else
		{
			node *temp = root;
			root = root -> right;
			delete(temp);
		}
	} 
	
	return root;
}

void bst::deletenode(int data)
{
	this -> root = deletenode(this -> root,data);
}

bool bst::search(node *root,int data)
{
	if(!root)
		return false;

	if(root -> data == data)
		return true;

	if(root -> data > data)
		return search(root -> left, data);

	return search(root -> right,data);
}

void bst::inorder()
{
	if(!this -> root)
	return;
	
	stack<node*> s;
	node *root = this -> root;
	
	while(1)
	{
		while(root)
		{
			s.push(root);
			root = root -> left;
		}
		
		if(s.empty())
		break;
		
		root = s.top();  s.pop();
		cout<<root -> data<<" ";
		root = root -> right;
	}
}

