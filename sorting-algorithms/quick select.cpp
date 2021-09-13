int quick_select(vector<int> &arr,int l,int r,int k)
{ 
    k = k - 1;

	while(l < r)
	{
	 	int i = l-1, j = r;
	 	int v = arr[r];
	 	
	 	// using random pivot
	    int pivot = rand() % (r-l+1); 
	    swap(arr[l + pivot],arr[r]);

	 	    while(true)
	 	    {
	 	        while(arr[++i] < v);
	 	        while(j > l and arr[--j] > v);
	 	         
	 	        if(i>=j)
	 	        break;

	 	        swap(arr[i],arr[j]);    
	 	    }
	 	     
	 	    swap(arr[r],arr[i]);
	 	     
	 	    if(i <= k)
	 	    l = i + 1;
	 	     
	 	    if(i >= k)
	 	    r = i - 1;
	}

	return(arr[k]);	
}

int recursive_quick_select(vector<int> &arr,int l,int r,int k)
{
	if(l >= r)
	    return a[r];
	
	int i = l - 1;
	int j = r;
	int v = arr[r];

	    while(true)
	    {
	     	while(arr[++i] < v);
	     	
	     	while(j > l and arr[--j] > v);
	     	
	     	if(i >= j)
	     	break;
	     	
	     	swap(arr[i],arr[j]);
		}
		 
		swap(arr[i],arr[r]);
		 
		if(i == k)
		    return arr[k];
		 
		if(i > k)
		   return recursive_quick_select(arr,l,i-1,k);
		 
		return recursive_quick_select(arr,i+1,r,k);
}
