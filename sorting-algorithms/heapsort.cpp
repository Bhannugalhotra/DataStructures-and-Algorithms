
void max_heapify(vector<int> &a,int i,int size)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	
	if(l < size and a[l] > a[largest])
	largest = l;
	
	if(r < size and a[r] > a[largest])
	largest = r;
	
	if(largest != i)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a,largest,size);
	}
}

void build_heap(vector<int> &a)
{
	int size = a.size();
	for(int i = (size-2)/2; i >= 0; i--)
	max_heapify(a,i,size);
}

void heapsort(vector<int> &a)
{
    build_heap(a);
	int size = a.size();

	for(int i = a.size()-1; i > 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		size--;
		max_heapify(a,0,size);
	}	
}