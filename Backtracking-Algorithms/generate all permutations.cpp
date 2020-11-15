#include<bits/stdc++.h>
using namespace std;

class generate_permutations
{
	int n;
	vector<int> a, set;
	vector<bool> visited;

public:

	generate_permutations()
	{
		cin >> n;

		a = vector<int>(n);
		set = vector<int>(n);
		visited = vector<bool>(n);

		for(int i = 0; i < n; i++)
			cin >> set[i];
	}

	vector<int> construct_candidate()
	{
		vector<int> candidates;

		for(int i=0; i < n;i++)
		if(!visited[i])
		candidates.push_back(i);

		return candidates;
	}

	void backtrack(int k)
	{
		if(k == n)
		{
			for(int i = 0; i < n; i++)
			cout<<a[i]<<" ";
			
			cout<<endl;

			return;
		}
		
		vector<int> candidates = construct_candidate();

		for(int i : candidates)
		{
			a[k] = set[i];
			visited[i] = true;
			
			backtrack(k+1);
			
			visited[i] = false;
		}
	}

	void solve()
	{
		backtrack(0);
	}

};

int main()
{
	generate_permutations sol;

	sol.solve();
}
