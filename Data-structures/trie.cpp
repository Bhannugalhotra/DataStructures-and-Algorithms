#include<iostream>
using namespace std;

class node
{
	public:
	node *arr[26];
	bool end_of_word;
	
	node()
	{
		for(int i=0; i < 26; i++)
		arr[i] = NULL;
		
		end_of_word = false;
	}
};

class trie
{
	public:
	node *root;
	
	trie()
	{
		root = new node;
	}
	
	node* insert(node *root ,string s, int i = 0);
	void insert(string s);
	void print_trie(node *root,string buffer,int l);
	bool search(node *root,string s,int l);
	bool search(string s);
};

node* trie::insert(node *root,string s,int i)
{
	if(!root)
	root = new node;
	
	if(i == s.length())
	root -> end_of_word = true;
	
	else
	root -> arr[s[i] - 'a'] = insert(root -> arr[s[i] - 'a'],s,i+1);
	
	return root;
}

void trie::insert(string s)
{
	node *root = this -> root;
	
	for(int i=0; i < s.length(); i++)
	{
		if(!root -> arr[s[i] - 'a'])
		root -> arr[s[i] - 'a'] = new node;
		
		root = root -> arr[s[i] - 'a'];
		
	}
	root -> end_of_word = true;
}

bool trie::search(node *root,string s,int l)
{
	if(!root)
	return false;
	
	if(l == s.length())
	return root -> end_of_word;
	
	return search(root -> arr[s[l] - 'a'],s,l+1);
}

bool trie::search(string s)
{
	node *root = this -> root;
	
	for(int i=0; i < s.length();i++)
	{
		if(!root -> arr[s[i] - 'a'])
		return false;
		
		root = root -> arr[s[i] - 'a'];
	}
	
	return (root and root -> end_of_word);
}
void trie::print_trie(node *root,string buffer,int l = 0)
{
	if(root -> end_of_word)
	cout<<buffer<<endl;
	
	if(!root)
		return;
	
    for(int i=0; i < 26; i++)
    {
    	if(!root -> arr[i])
    	continue;
    	
        char curr = i + 'a';
    	print_trie(root -> arr[i],buffer + curr,l+1);
	}
}
int main()
{
	int a,b,c;,d,e,f,g;

	trie t;
	
	int n;
	cin>>n;
	string s;
	
	while(n--)
	{
		cin>>s;
		t.insert(t.root,s,0);
	}
	
	t.print_trie(t.root,"");
}

