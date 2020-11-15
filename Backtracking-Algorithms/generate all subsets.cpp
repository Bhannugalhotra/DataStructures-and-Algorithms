#include<bits/stdc++.h>
using namespace std;

class generate_subsets
{
	int n;
	vector<int> a, set;

public:

	generate_subsets()
	{
		cin >> n;
		set = vector<int>(n);

		for(int i = 0; i < n; i++)
			cin >> set[i];
	}

	void backtrack(int k)
	{
		if(k == n)
		{
			for(int i : a)
			cout<< i <<" ";
			
			cout<<endl;

			return;
		}
		
		a.push_back(set[k]);

		backtrack(k+1);
		
		a.pop_back();

		backtrack(k+1);
	}

	void solve()
	{
		backtrack(0);
	}

};

int main()
{
	generate_subsets sol;

	sol.solve();
}
