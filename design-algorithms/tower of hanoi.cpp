#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char frompeg, char topeg, char auxpeg)
{
	if(n==1)
	{
		cout<<"move disk 1 from "<<frompeg<<" to "<<topeg<<endl;
		return;
	}
	
	tower_of_hanoi(n-1,frompeg,auxpeg,topeg);
	
	cout<<"move disk "<< n <<" from "<<frompeg<<" to "<<topeg<<endl;
	
	tower_of_hanoi(n-1,auxpeg,topeg,frompeg);
}

int main()
{
	int n = 4;
	
	tower_of_hanoi(n,'A','C','B');
	
	return 0;
}
