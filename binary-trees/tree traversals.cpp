
class node
{
public:
	int data;
	node *left, *right;

	node(int x) : data(x) , left(NULL), right(NULL) {};
};

void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void levelorder(node *root);
void iterative_preorder(node *root);
void iterative_inorder(node *root);
void iterative_postorder1(node *root);
void iterative_postorder2(node *root)
void iterative_postorder3(node *root)

void preorder(node *root)
{
	if(!root)
	return;
	
	cout << root -> data << endl;
	preorder(root -> left);
	preorder(root -> right);
	
}

void inorder(node *root)
{
	if(!root)
	return;
	
	inorder(root -> left);
	cout << root -> data << endl;
	inorder(root -> right);
}

void postorder(node *root)
{
	if(!root)
	return;
	
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << endl;
}

void levelorder(node *root)
{
	if(!root)
	return;
	
	queue <node*>q;
	q.push(root);
	
	while(!q.empty())
	{
		node *root = q.front();
		q.pop();
		print(root -> data);
		
		if(root -> left)
		q.push(root -> left);
		
		if(root -> right)
		q.push(root -> right);
	}
}

void iterative_preorder(node *root)
{
	stack <node*> s;

	while(true)
	{
		while(root)
		{
			cout << root -> data << endl;
			s.push(root);
			root = root -> right;
		}

		if(s.empty())
		break;
		
		root = s.top();  s.pop();
		root = root -> left;
	 } 
}

void iterative_inorder(node *root)
{
	stack <node*> s;
	 
	 while(true)
	 {
	 	while(root)
	 	{
	 		s.push(root);
	 		root = root -> left;
		}

		if(s.empty())
		break;
		 
		root = s.top(); s.pop();

		cout << root -> data << endl;
		root = root -> right;
	 }
 
}

void iterative_postorder1(node *root)
{
	stack<node*> s;
	
	while(true)
	{
		while(root)
		{
			s.push(root);
			s.push(root);
			root = root -> left;
		}

		if(s.empty())
		break;
		
		root = s.top();  s.pop();
		
		if(root == s.top())
		root = root -> right;
		
		else
		{
			cout << root -> data << endl;
			root = NULL;
		}
	}
} 

void iterative_postorder2(node *root)
{
	node *prev = NULL;  
	stack<node*> s;
	
	while(1)
	{
		while(root)
		{
			s.push(root);
			root = root -> left;
		}
		
		if(s.empty())
		break;
		
		root = s.top();
		
		if(root -> right == NULL || root -> right == prev)
		{
			cout << root -> data << endl;
			s.pop();
			prev = root;
			root = NULL;
		}
		
		else
		root = root -> right;
	}
}

// reverse of preorder
void iterative_postorder3(node *root)
{
	stack<node*> s;
	stack<int> s2;
	
	while(1)
	{
		while(root)
		{
			s.push(root);
			s2.push(root -> data);
			
			root = root -> right;
		}

		if(s.empty())
		break;
		
		root = s.top();  s.pop();
		root = root -> left;
	}
	
	while(!s2.empty())
	{
		cout << root -> data << endl;
		s2.pop();
	}
}