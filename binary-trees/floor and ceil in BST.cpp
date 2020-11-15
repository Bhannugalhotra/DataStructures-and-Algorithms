void floor(node *root,int key,int &fl)
{
	if(!root)
	return;
	
	if(root -> data < key)
	{
		fl = root -> data;
		 
	    floor(root -> right,key,fl);
	}
	
	else 
	floor(root -> left,key,fl);	
}

void ceil(node *root, int key, int &cl)
{
	if(!root)
	return;
	
	if(root -> data > key)
	{
		cl = root -> data;
		ceil(root -> left,key,cl);
	}
	
	else
	ceil(root -> right,key,cl);
}