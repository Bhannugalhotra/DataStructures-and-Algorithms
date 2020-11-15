#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;

vp point = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

class knight_tour
{
	int N;
	vector<vector<int>> a;
	bool finished;

public:

	knight_tour(int x)
	{
		N = x;

		a = vector<vector<int> >(N,vector<int>(N));

		finished = false;
	}

	void process_solution()
	{
		cout<<"knight tour :"<<endl;
		for(int r = 0; r < N; r++)
		{
			for(int c = 0; c < N; c++)
			cout<<a[r][c]<<" ";
			
			cout<<endl;
		}
	}

	vp construct_candidate(pair<int,int> place,int k)
	{
		vp candidates;
		for(int i = 0; i < point.size(); i++)
		{
			int row = place.first + point[i].first;
			int col = place.second + point[i].second;
			
			if(row < N and col < N and row >= 0 and col >= 0 and a[row][col] == 0)
			candidates.push_back({row,col});
		}

		return candidates;
	}
	void backtrack(int k,pair<int,int> place)
	{
		if(k == N * N)
		{
			process_solution();
			finished = true;
			return;
		}
		
		k = k + 1;
		vp candidates = construct_candidate(place,k);
		for(pair<int,int> i : candidates)
		{
			int row = i.first;
			int col = i.second;
			
			a[row][col] = k;

			backtrack(k,i);
			
			if(finished)
			return;
			
			a[row][col] = 0;
		}
	}

	void solve()
	{
		a[0][0] = 1;
		backtrack(1,{0,0});

		if(!finished)
			cout<<"tour not possible"<<endl;
	}
};

int main()
{
	
	knight_tour sol(5);

	sol.solve();
}
