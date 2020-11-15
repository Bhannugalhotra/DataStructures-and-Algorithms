#include<bst.h>

int LCA(node *root,int a,int b)
{
	if(!root)
	return -1;
	
	if(root -> data > a and root -> data < b)
	return root -> data;
	
	if(root -> data < a and root -> data > b)
	return root -> data;
	
    else if(root -> data == a or root -> data == b)
	return root -> data;
	
	else if(root -> data < a)
	return LCA(root -> right,a,b);
	
	else
	return LCA(root -> left,a,b);
}
