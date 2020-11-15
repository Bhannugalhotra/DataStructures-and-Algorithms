
class node
{
public:
	char data;
	node *left, *right;

	node(char x) : data(x) , left(NULL), right(NULL) {};
};

node* expression_tree(string exp)
{
	stack<node*> s;
	
	for(char c : exp)
	{
		node *newnode = new node(c);
		
		if((c >= 'a' and c <= 'z'))
		s.push(newnode);
		
		else
		{
			if(!s.empty())
			{
				newnode -> right = s.top();
				s.pop();
			}
			
			if(!s.empty())
			{
				newnode -> left = s.top();
				s.pop();
			}
			
			s.push(newnode);
		}
	}
	
	if(s.size() > 1)
	cout<<"expression not correct"<<endl;
	
	return s.top();
}
