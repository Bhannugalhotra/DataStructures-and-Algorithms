#include<bits/stdc++.h>
using namespace std;


class n_queen_finder
{
	int N;
	vector<vector<int>> a;
	int solutions;

public:

	n_queen_finder(int x)
	{
		N = x;
		solutions = 0;
		a = vector<vector<int>> (N, vector<int>(N));
	}

	void process_solution()
	{
		solutions++;
		for(int r = 0; r < N ; r++)
		{
			for(int c = 0; c < N ; c++)
			cout<<a[r][c]<<" ";
			
			cout<<endl;
		}

		cout << endl;
	}

	bool in_column(int row,int col)
	{
		for(int r = 0; r < row; r++)
		if(a[r][col])
		return false;
		
		return true;
	}

	bool in_diagonal(int row, int col)
	{
		int r = row,c = col;
		while(r >= 0 && c < N )
		{
			if(a[r][c])
			return false;
			
			r--;
			c++;
		}
		
		r = row;
		c = col;
		
		while(r >= 0 && c >= 0)
		{
			if(a[r][c])
			return false;
			
			r--;
			c--;
		}
		
		return true;
	}
	vector<int> construct_candidate(int k)
	{
		vector<int> candidates;

		for(int i = 0; i < N; i++)
		{
			if(in_column(k,i) && in_diagonal(k,i))
			candidates.push_back(i);
		}

		return candidates;
	}

	void backtrack(int k)
	{
		if(k == N)
		{
			process_solution();
			return;
		}
		
		vector<int> candidates = construct_candidate(k);
			
		for(int i : candidates)
		{
			a[k][i] = 1;
			
			backtrack(k+1);
			
			a[k][i] = 0;
		}
	}

	void solve()
	{
		backtrack(0);

		cout << solutions << endl;
	}
};

int main()
{
	n_queen_finder sol(5);

	sol.solve();
}
