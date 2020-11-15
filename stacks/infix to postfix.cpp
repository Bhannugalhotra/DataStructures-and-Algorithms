
int priority(char op)
{
	if(op == '^')
	return 3;
	
	else if(op == '/' || op == '*')
	return 2;
	
	else if(op == '+' || op == '-')
	return 1;
	
    else 
    return 0;
}

string infix_to_postfix(string text)
{
	stack<char> s;
	string ans;
	
	for(int i = 0; i < text.size(); i++)
	{
		if(text[i] == '(')
		s.push(text[i]);
		
		else if((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= '0' and text[i] <= '9'))
		ans = ans + text[i];
		
		else if(text[i] == ')')
		{
		  	while(!s.empty() and s.top() != '(')
		  	{
		  		ans = ans + s.top();
		  		s.pop();
		  	}
	
		  	s.pop();	
		 } 
		 
		else
		{
		 	while(!s.empty() and s.top() != '(' and priority( s.top()) >= priority(text[i]))
		 	{
		 		ans = ans + s.top();
				s.pop();	
			}

			s.push(text[i]);
		}
	}

	while(!s.empty())
	{
		ans = ans + s.top();
		s.pop();
	}
	
	return ans;
}