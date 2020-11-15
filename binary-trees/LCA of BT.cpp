node* lca(node *root,int a,int b)
{
	if(!root)
	return NULL;
	
	if(root -> data == a or root -> data == b)
	return root;
	
	node *left = lca(root -> left,a,b);
	node *right = lca(root -> right,a,b);
	
	if(left and right)
	return root;
	
	else if(left)
	return left;
	
	else
	return right;
}