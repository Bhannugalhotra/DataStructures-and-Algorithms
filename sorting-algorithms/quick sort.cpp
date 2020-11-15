
void quicksort(vector<int> &arr,int l, int r)
{
	if(r <= l)
	return;
	
	int i = l - 1,j = r;
	int v = arr[r];

	// using random pivot
    int pivot = rand() % (r-l+1); 
    swap(arr[l + pivot],arr[r]);

	    while(true)
	    {
	     	while(arr[++i] < v);

	     	while(j > l-1 and arr[--j] > v);

	     	if(i >= j)
	     	break;
	     	
	     	swap(arr[i],arr[j]);	
		}
		 
		swap(arr[i],arr[r]);
		 
		quicksort(arr,l,i-1);
		quicksort(arr,i+1,r);	
}

void three_way_quicksort(vector<int> &arr, int l, int r)
{
	if(r <= l)
	return;
	
	int lt = l, gt = r;
	int v = arr[l];
	
    for(int i = l; i <= gt; )
	{
	 	if(arr[i] < v)
	 	    swap(arr[i++],arr[lt++]);

	    else if(arr[i] > v)
		 	swap(arr[i],arr[gt--]);

		else
		    i++;
    }
	    
			    
	three_way_quicksort(arr,l,lt-1);
	    
	three_way_quicksort(arr,gt+1,r);
               
}          

