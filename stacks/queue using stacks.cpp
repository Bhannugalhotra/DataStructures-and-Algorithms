
template<typename type>
class queue
{
	stack<type> s1;
	stack<type> s2;
    int size = 0;
	public:
		
	bool empty()
	{
		return size == 0;
	}
	
	void push(type data)
	{
		s1.push(data);
		size++;
	}
	
	type front()
	{
		if(size == 0)
		exit(1);
		
		if(s2.empty())
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		
		return s2.top();
	}
		
	void pop()
	{
		if(size == 0)
		exit(1);
		
		if(s2.empty())
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		
		s2.pop();
		size--;
	}
};

