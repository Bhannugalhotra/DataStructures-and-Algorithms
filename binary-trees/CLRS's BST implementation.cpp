#include<bits/stdc++.h>
using namespace std;

class node
{
public:

	int data;
	node *right,*left,*p;

	node(int x) : data(x), left(NULL), right(NULL), p(NULL) {};
};

class bst
{
public:
	node *root;

	bst() : root(NULL) {};
};

node* find(node *root, int data);
node* findmax(node *root);
node* findmin(node *root);
node* succsessor(bst &t, int data);
node* predesessor(bst &t, int data);
void insert(bst &t, int data);
void deletenode(bst &t);
void transplant(bst &t, node *u, node *v);
void inorder(node *root);
void print(int data);

node* find(node *root, int data)
{
	if(!root)
	return NULL;
	
	if(data < root -> data)
	return find(root -> left,data);
	
	else if(data > root -> data)
	return find(root -> right, data);
	
	else
	return root;
	
}

node* findmin(node *root)
{
	if(!root)
	return NULL;
	
	while(root -> left)
	root = root -> left;
	
	return root;
}

node* findmax(node *root)
{
	if(!root)
	return NULL;
	
	while(root -> right)
	root = root -> right;
	
	return root;
}

void insert(bst &t, int data)
{
	node *newnode = new node(data);
	
	node *temp = t.root;
	node *tp = NULL;
	
	while(temp)
	{
		tp = temp;
		
		if(data < temp -> data)
		temp = temp -> left;
		
		else
		temp = temp -> right;
	}
	
	newnode -> p = tp;
	
	if(!tp)
	t.root = newnode;
	
	else if(data < tp -> data)
	tp -> left = newnode;
	
	else
	tp -> right = newnode;
}

node* succsessor(bst &t, int data)
{
   	node *x = find(t.root,data);
   	
   	if(x -> right)
   	return findmin(x -> right);
   	
   	node *y = x -> p;
   	while(y != NULL && x == y -> right)
   	{
   	    x = y;
		y = y -> p;	
	}
	return y;
}

node* predesessor(bst &t, int data)
{
	node *x = find(t.root,data);
	
	if(x -> left)
	return findmax(x -> left);
	
	node *y = x -> p;
	
	while( y != NULL && x == y -> left)
	{
		x = y;
		y = y -> p;
	}
	return y;
}

void transplant(bst &t, node *u, node *v)
{
   if(u -> p == NULL)
   t.root = v;
   
   else if(u == u -> p -> left)
   u -> p -> left = v;
   
   else
   u -> p -> right = v;
   
   if(v != NULL)
   v -> p = u -> p;
     	
}

void deletenode(bst &t,int data)
{
   node *z = find(t.root,data);
   
   if(z -> left == NULL)
   transplant(t,z,z -> right);
   
   else if(z -> right == NULL)
   transplant(t,z,z -> left);
   
   else
   {
   	node *y = findmin(z -> right);
   	
   	if(y -> p != z)
   	{
   	    transplant(t,y,y -> right);
	  	y -> right = z -> right;
	  	y -> right -> p = y;
    }
   
    
    transplant(t,z,y);
    y -> left = z -> left;
    y -> left -> p = y; 
   	 
   }
}

void inorder(node *root)
{
	if(!root)
	return;
	
	inorder(root -> left);
	print(root -> data);
	inorder(root -> right);
}

void print(int data)
{
	cout<<data<<" ";
}


int main()
{
	bst t;
	
	cout<<"enter no of elements"<<endl;
	int n;
	cin>>n;
	
	while(n--)
	{
	  int k;
	  cin>>k;
	  insert(t,k);
	}
    cout <<endl;
	cout<<"enter no of elements to be deleted"<<endl;
	int z;
	cin>>z;
	while(z--)
	{
		int k;
		cin>>k;
		deletenode(t,k);
	}
 
	inorder(t.root);
	cout <<endl;
	node *s = succsessor(t,5);
	node *p = predesessor(t,5);
	print(s -> data);
	print(p -> data);
	
	return 0;
}
