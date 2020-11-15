void shell_sort(vector<int> &a, int n)
{
	int h;
	for( h = 1; h <= n/9 ; h = h*3 +1);
	
	for(; h > 0; h = h/3)
	{
		for(int i = h ;i < n; i++)
		{
			int v = a[i];
			int j = i;
			
			while(j >= h and a[j-h] > v)
			{
			    a[j] = a[j-h];
			  	j = j - h;
			}

			a[j] = v;
		}
	}
}