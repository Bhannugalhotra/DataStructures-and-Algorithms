

void selection_sort(vector<int> &a,int n)
{
	for(int i = 0 ; i < n ;i++)
	{
		int min = i;
		for(int j = i + 1;j < n;j++)
		{
			if(a[j] < a[min])
			min = j;
		}
		swap(a[min],a[i]);
	}
}


void bubble_sort(vector<int> &a, int n)
{
	for(int i = n - 1; i > 0 ;i--)
	{
		for(int j = 1; j <= i ;j++)
		{
			if(a[j-1] > a[j])
			swap(a[j-1],a[j]);
		}
	}
}

void insertion_sort(vector<int> &a, int n)
{
	for(int i = 1; i < n ;i++)
	{
		int v = a[i];
		int j = i;

		while(j >= 1 && a[j-1] > v)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}
