
class node
{
public:
	int data;
	node *left, *right;

	node(int x) : data(x) , left(NULL), right(NULL) {};
};


void succseccor(node *root,int data,int &succ)
{
	if(!root)
	return;
	
	if(root -> data > data)
	{
		succ = root -> data;
		succseccor(root -> left,data,succ);
	}
	
	else if(root -> data < data)
	succseccor(root -> right,data,succ);
	
	else if(root -> right)
	{
		node *temp = min(root -> right);
		succ = temp -> data;
	}
	
}

void predeseccor(node *root,int data,int &pred)
{
	if(!root)
	return;
	
	if(root -> data < data)
	{
		pred = root -> data;
		predeseccor(root -> right,data,pred);
	}
	
	else if(root -> data < data)
	predeseccor(root -> left,data,pred);
	
	else if(root -> left)
	{
		node *temp = max(root -> left);
		pred = temp -> data;
	}
}

int iterative_succseccor(node *root,int data)
{
	int succ = -1;
	
	while(root && root -> data != data)
	{
		if(root -> data > data)
		{
			succ = root -> data;
			root = root -> left;
		}
		
		else
		root = root -> right;	
	}
	
	if(!root)
	return -1;
	
	if(root -> right)
	{
		node *temp = min(root -> right);
		succ = temp -> data;
	}
	
	return succ;
}