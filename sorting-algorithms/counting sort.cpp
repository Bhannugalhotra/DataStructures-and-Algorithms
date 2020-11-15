
void counting_sort(vector<int> &arr, int n, int m)
{
	vector<int> count(m+1), aux(n);

	for(int i = 0; i < n ; i++)
	    ++count[arr[i]];
	 	
	for(int i = 1 ; i <= m ; i++)
		count[i] += count[i-1];
		
	for(int i = n-1; i >= 0 ; i--)
	{
		aux[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	 
	for(int i = 0; i < n ;i++)
		arr[i] = aux[i];
}