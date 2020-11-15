
template<typename type>
class stack
{
	type *arr;
	int capacity;
	int tp;
	
	public:
		
	stack()
	{
		capacity = 10000;
		arr = new type[capacity];
		tp = -1;
	}
	
	bool empty()
	{
		return tp == -1;
	}
	
	int size()
	{
		return tp + 1;
	}
	
	void push(type data)
	{
		if(tp + 1 == capacity)
		resize();
		
		arr[++tp] = data;
	}
	
	type top()
	{
		if(empty())
		return -1;
		
		return arr[tp];
	}
	
	void pop()
	{
		if(empty())
		return;
		
		tp--;
	}
	
	void resize()
	{
		type *aux = arr;
		
		arr = new t[capacity*2];
		
		for(int i = 0; i < capacity; i++)
		arr[i] = aux[i];
		
		capacity *= 2;
		
		delete(aux);
	}
};