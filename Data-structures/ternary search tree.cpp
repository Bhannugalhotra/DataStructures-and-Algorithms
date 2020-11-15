#include<bits/stdc++.h>
using namespace std;

struct node;
struct tst;

node* createnode(char data);
tst* createtst(void);
node* insert(node *root, string s, int level);
void insert(tst *t,string s);
int search(node *root, string s, int level);
node *deletestring(node *root, string s, int level);
void deletestring(tst *t, string s);
void display(node *root, string s, int level);
void display(tst *t);
int is_leaf(node *root);

struct node
{
	char data;
	bool end_of_string;
    node *left, *right, *mid;	
};

struct tst
{
	node *root;
};

tst* createtst()
{
	tst *t = new tst();
	t -> root == NULL;
	
	return t;
}

node* createnode(char data)
{
	node *newnode = new node();
	newnode -> data = data;
	newnode -> end_of_string = 0;
	newnode -> left = newnode -> right = newnode -> mid = NULL;
	
	return newnode;
}

node* insert(node *root, string s, int level)
{
	if(root == NULL)
	root = createnode(s[level]);
	
	if(s[level] < root -> data)
	root -> left = insert(root -> left,s,level);
	
	else if(s[level] > root -> data)
	root -> right = insert(root -> right,s,level);
	
	else if(level < s.length() - 1)
	root -> mid = insert(root -> mid,s,level + 1);
	
	else
	root -> end_of_string = 1;
	
	return root;
}

int search(node *root,string s, int level)
{
	if(root == NULL)
	return 0;
	
	if(root -> data < s[level])
	return search(root -> right,s,level);
	
	else if(root -> data > s[level])
	return search(root -> left,s ,level);
	
	else if(level < s.length() - 1)
	return search(root -> mid ,s, level + 1);
	
	else
	return root -> end_of_string;
}

int is_leaf(node *root)
{
	int a = 1;
	if(root -> right)
	a = 0;
	
	if(root -> left)
	a = 0;
	
	if(root -> mid)
	a = 0;
	
	return a;
}

node* deletestring(node *root,string s, int level)
{
	if(root == NULL)
	return NULL;
	
	if(level == s.length() - 1)
	{
	if(root -> end_of_string)
	{
		if(is_leaf(root))
		{
		    delete(root);
		    root = NULL;
	    }  
	    else
	    root -> end_of_string = 0;
	    
	    return root;
	}
    }
	
	if(s[level] < root -> data)
	root -> left = deletestring(root -> left,s,level);
	
	else if(s[level] > root -> data)
	root -> right = deletestring(root -> right,s,level);
	
	else
	root -> mid = deletestring(root -> mid,s,level+1);
	
	if(is_leaf(root) && root -> end_of_string == 0)
	{
		delete(root);
		root = NULL;
	}
	return root;
}

void display(node *root, string s, int level)
{
	if(root == NULL)
	return;
	
	display(root -> left,s,level);
	
	s[level] = root -> data;
	
	if(root -> end_of_string)
	{
		s[level +1] = '\0';
		cout<<s<<endl;
	}
	
	display(root -> mid,s,level+1);
	display(root -> right,s,level);
}

// driver for insert
void insert(tst *t,string s)
{
	t -> root = insert(t -> root,s,0);
}

// driver for deletestring
void deletestring(tst *t, string s)
{
	t -> root = deletestring(t -> root,s,0);
}

// driver for display
void display(tst *t)
{
	string s = "                         ";
	display(t -> root,s,0);
}

// random string generator
char genRandom(char alphanum[],int stringLength)
{
    return alphanum[rand() % stringLength];
}


int main()
{
	char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum) - 1;
    
    
	tst *t = createtst();
//	cout<<"no of strings";
	int n = 200000;
//	cin>>n;
	string s[n];
	
	for(int i=0; i<n ;i++)
	{
		
		for(int j = 0; j<5;j++)
		{
		   s[i] = s[i] + genRandom(alphanum,stringLength);	
		}
//			cout<<s[i]<<endl;

	 	insert(t,s[i]);
	}
	cout<<endl;

    int ans = search(t -> root,"tytrhjj",0);
    cout <<ans <<endl;
    
     
//    display(t);
    
    return 0;
}


