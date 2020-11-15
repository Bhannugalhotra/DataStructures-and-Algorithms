#include<iostream>
using namespace std;

class max_heap
{
	int capacity;
	int size;
	vector<int> a;
	
	public:
	max_heap(int cap = 50) : a(cap),capacity(cap),size(0) {};
	
	int left(int i);
	int right(int i);
	int parent(int i);
	void max_heapify(int i);
	void insert(int data);
	int max();
	int extract_max();
	int sizee();
	int left_child(int element);
	int right_child(int element);
};

int max_heap::sizee()
{
	return size;
}
int max_heap::left(int i)
{
	int l = 2*i + 1;
	if(l > size - 1)
	l = -1;
	
	return l;
}
int max_heap::right(int i)
{
	int r = 2*i + 2;
	if(r > size - 1)
	r = -1;
	
	return r;
}
int max_heap::parent(int i)
{
	int p = (i-1)/2;
	if(p < 0)
	p = -1;
	
	return p;
}

void max_heap::max_heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	
	if(l != -1 && a[l] > a[largest])
	largest = l;
	
	if(r != -1 && a[r] > a[largest])
	largest = r;
	
	if(largest != i)
	{
		swap(a[i],a[largest]);
		
		max_heapify(largest);
	}
}

void max_heap::insert(int data)
{
	if(size == capacity)
	return;
	
	size++;
	int i = size - 1;
	while( i > 0 && a[parent(i)] < data)
	{
		a[i] = a[parent(i)];
		i = parent(i);
	}
	a[i] = data;
}

int max_heap::max()
{
	if(size <= 0)
	return -1;
	
	return a[0];
}

int max_heap::extract_max()
{
	if(size <= 0)
	return -1;
	
	int data = a[0];
	a[0] = a[size - 1];
	size--;
	
	max_heapify(0);
	return data;
}

int max_heap::left_child(int element)
{
	for(int i=0; i< size; i++)
	if(a[i] == element)
	if(left(i) != -1)
	return a[left(i)];
	
	return -1;
}
int max_heap::right_child(int element)
{
	for(int i=0; i< size; i++)
	if(a[i] == element)
	if(right(i) != -1)
	return a[right(i)];
	
	return -1;
}

int kth_element(max_heap horg,int k)
{
	max_heap haux;
	int element;
	int count = 0;
	k = horg.sizee() - k + 1;
	haux.insert(horg.max());
	while(true)
	{
		element = haux.extract_max();
		if(++count == k)
		return element;
		
		haux.insert(horg.left_child(element));
		haux.insert(horg.right_child(element));
	}
}

int main()
{
	max_heap heap;
	
	heap.insert(1011000);
	heap.insert(200000);
	heap.insert(500000);
	heap.insert(3000);
	heap.insert(40000);
	
	cout<<kth_element(heap,4);
	cout<<heap.extract_max()<<endl;
	cout<<heap.extract_max()<<endl;
	
	return 0;
}

