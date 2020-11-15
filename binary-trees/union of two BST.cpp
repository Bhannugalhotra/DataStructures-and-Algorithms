

void inorder_trv(node *root,node &*head)
{
	if(!root)
	return;
	
	inorder_trv(root -> left,head);
	
	head -> right = root;
	root -> left = head;
	head = head -> right;
	
	inorder_trv(root -> right,head);
}

node* convert_to_list(bst *t)
{
	if(!t -> root)
	return NULL;
	
	node *head = new node(0);
	node *temp = head;
	
	convert_to_list(t -> root,temp);
	
	temp = head;
	head = head -> right;
	head -> right -> left = NULL;
	delete(temp);
	
	return head;
}

node* merge(node *a,node *b)
{
	if(!a)
	return b;
	
	if(!b)
	return a;
	
	node *result;
	
	if(a -> data < b -> data)
	{
		result = a;
		result -> right = merge(a -> right,b);
	}
	
	else
	{
		result = b;
		result -> right = merge(a,b -> right);
	}
	
	return result;
}

node* merge_list(node *head1,node *head2)
{
	node *head = merge(head1,head2);
	head -> left = NULL;

	for(node *itr = head;itr -> right;itr = itr -> right)
	itr -> right -> left = itr;
	
	return head;	
}

node* mid_of_list(node *head)
{
	node *slow = head;
	node *fast = head;
	
	while(fast && fast -> right)
	{
		fast = fast -> right -> right;
		slow = slow -> right;
	}
	
	return slow;
}
node* convert_to_bst(node *head)
{
	if(!head)
	return NULL;
	
	node *mid = mid_of_list(head);
	
	if(!mid -> left and !mid -> right)
	return mid;
	
	if(mid -> left)
	mid -> left -> right = NULL;

	if(mid -> right)
	mid -> right -> left = NULL;
	
	mid -> left = convert_to_bst(head);
	mid -> right = convert_to_bst(mid -> right);
	
	return mid;
}

bst* _union(bst *t1,bst *t2)
{
	node *head1 = convert_to_list(t1);
	node *head2 = convert_to_list(t2);
	
	node *head = merge_list(head1,head2);
 
	bst *t  = new bst();
	t -> root = convert_to_bst(head);
	
	return t;
}