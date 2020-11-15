#include<bits/stdc++.h>
using namespace std;

int postfix_evaluation(string text)
{
	stack<char> s;
	
	for(int i = 0; i < text.size(); i++)
	{
		if(isdigit(text[i]))
		s.push(text[i] - '0');
		
		else
		{
			int a = s.top(); s.pop();
			int b = s.top(); s.pop();
			
			switch(text[i])
			{
				case '+':
					s.push(b + a);
					break;
					
				case '-':
				    s.push(b - a);
					break;
					
			    case '/':
				    s.push(b / a);
					break;
				
				case '*':
				    s.push(b*a);
				    break;
				    
				case '^':
				    s.push(b^a);
					break;					
			}
		}
	}
	
	return s.top();
}

int main()
{
	string text;
	cout<<"enter postfix expression"<<endl;
	cin >> text;
	
	int ans = postfix_evaluation(text);
	
	cout<<ans<<endl;
	
	return 0;
}
