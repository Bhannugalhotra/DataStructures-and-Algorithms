
int is_same(char a,char b)
{
	if(a == '(' && b == ')')
	return 1;
	
    else if(a == '{' && b == '}')
	return 1;
	
	else if(a == '[' && b == ']')
	return 1;
	
	else
	return 0;	
} 

bool is_balanced(string text)
{
	stack<char> s;
	
	for(int i = 0; i < text.size(); i++)
	{
		if(text[i] == '(' or text[i] == '{' or text[i] == '[')
		s.push(text[i]);
		
		else if(text [i] == ')' or text[i] == '}' or text[i] == ']')
		{
		    if(s.empty())
		    return false;
		    
			char c = s.top();  s.pop();
			
			if(!is_same(c,text[i]))
			return false;
		}
	}
	
	if(!s.empty())
	return false;
	
	return true;
}