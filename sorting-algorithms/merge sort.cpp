
void merge(vector<int> &arr,int l,int mid,int r,ivector<int> &aux)
{
	int i, j;
	i = l;
	j = mid + 1;
	
	for(int z = l ; z <= r ; z++)
	aux[z] = arr[z];
	       
	
    for(int k = l; k <= r; k++)
    { 	 
     	if(i > mid)
     	arr[k] = aux[j++];  
     	
     	else if(j > r)
        arr[k] = aux[i++];  
     	
     	else if(aux[i] < aux[j])
     	arr[k] = aux[i++];
     	
     	else
     	arr[k] = aux[j++];	
	}	  
}

void merge_sort(vector<int> &arr,int l,int r,int aux[])
{
	if(r <= l)
	return;
	
	int mid = l + ((r - l) >> 1);
	
    merge_sort(arr,l,mid,aux);
    merge_sort(arr,mid+1,r,aux);
     
    merge(arr,l,mid,r,aux);
	     
}
void recursive_merge_sort(vector<int> &arr, int n)
{
	vector<int> aux(n);
	merge_sort(arr,0,n-1,aux);
}

void iterative_merge_sort(vector<int> &arr,int n)
{
    vector<int> aux(n);
	int sz , l;
 
	for(sz = 1; sz < n ; sz += sz)
	{ 
		for(l = 0 ; l < n-sz ; l += sz + sz)
		merge(arr, l , l +sz-1 , min(l+sz+sz-1,n-1), aux);
	}
}
