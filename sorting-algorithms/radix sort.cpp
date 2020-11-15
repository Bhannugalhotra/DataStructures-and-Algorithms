
void counting_sort(vector<int> &arr,int exp) 
{ 
    int n = arr.size();
    vector<int> aux(n), count(10);   
   
    for (int i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = n - 1; i >= 0; i--) 
    { 
        aux[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
   
    for (int i = 0; i < n; i++) 
        arr[i] = aux[i]; 
} 
  
void radix_sort(vector<int> &arr) 
{ 
    int n = arr.size();
    int m = *max_element(begin(arr),end(arr));

    for (int exp = 1; m/exp > 0; exp *= 10) 
    counting_sort(arr,exp);
} 