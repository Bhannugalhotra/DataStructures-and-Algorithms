
int postorder(node *root,int &diameter)
{
	if(!root)
	return 0;
	
	int left = postorder(root -> left, diameter);

	int right = postorder(root -> right, diameter);
	
	diameter = max(diameter,right + left + 1);
	
	return (left > right) ? left+1 : right+1;	
}

int diameter_of_BT(node *root)
{
	int diameter = 0;

	postorder(root,diameter);

	return diameter;
}
