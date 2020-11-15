#include<bits/stdc++.h>
using namespace std;

class sudoku_solver
{
    int n;
    vector<vector<int>> a;
    bool finished;
    
    public:
    
    sudoku_solver()
    {
        n = 9;
        finished = false;
        
        a = vector<vector<int> >(n,vector<int>(n));
     
        for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
        cin >> a[i][j];
    }
    
    void process_solution()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            cout<< a[i][j] <<" ";

            cout<<endl;
        }
        
        cout<< endl;
    }
    
    bool in_row(int r,int c,int num)
    {
        for(int i = 0; i < n; i++)
        if(a[i][c] == num)
        return false;
        
        return true;
    }
    
    bool in_col(int r,int c,int num)
    {
        for(int i = 0; i < n; i++)
        if(a[r][i] == num)
        return false;
        
        return true;
    }
    
    bool in_box(int r,int c,int num)
    {
        r = r - r % 3;
        c = c - c % 3;
        
        for(int i = r; i < r+3; i++)
        for(int j = c; j < c+3; j++)
        if(a[i][j] == num)
        return false;
        
        return true;
    }
    vector<int> construct_candidates(int r,int c)
    {
        vector<int> candidates;
        
        for(int num = 1; num <= 9; num++)
        if(in_row(r,c,num) && in_col(r,c,num) && in_box(r,c,num))
        candidates.push_back(num);

        return candidates;
    }
    
    void backtrack(int k)
    {
        if(k == n * n )
        {
            process_solution();
            finished = true;
            return;
        }
        
        int r = k % 9;
        int c = k / 9;
        
        if(a[r][c] != 0)
        {
            backtrack(k+1);
            return;
        }
        
        vector<int> candidates = construct_candidates(r,c);
        
        for(int i : candidates)
        {
            a[r][c] = i;
            
            backtrack(k+1);
            
            if(finished)
            return;
        }
        
        a[r][c] = 0;
    }
    void solve()
    {
        backtrack(0);
    }
};
        
int main()
{
    sudoku_solver sol;
        
    sol.solve();
}
