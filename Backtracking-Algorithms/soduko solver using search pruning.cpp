#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vp;
#define N 9

bool is_a_solution(int m[N][N]);
void process_solution(int m[N][N]);
void construct_candidate(vp &a,int k,int m[N][N],int c[],int &ncandidate);
bool next_square(int &row,int &col,int m[N][N]);
void possible_values(int row,int col,int m[N][N],bool possible[]);
bool usedinrow(int row,int num,int m[N][N]);
bool usedincol(int col,int num, int m[N][N]);
bool usedinbox(int startrow,int startcol,int num,int m[N][N]);
void make_move(vp &a,int m[N][N],int k,int value);
void unmake_move(vp &a,int m[N][N],int k);
void backtrack(vp &a,int k,int m[N][N],bool &finished);
void sudoku();
void read_matrix(int m[N][N]);
int constrained_selection(int &row,int &col,int m[N][N]);
void look_ahead(int row,int col,int m[N][N],bool possible[]);

bool is_a_solution(int m[N][N])
{
	for(int r=0; r<N; r++)
	for(int c=0; c<N; c++)
	if(m[r][c] == 0)
	return false;
	
	return true;
}

void process_solution(int m[N][N])
{
	cout<<"sudoku :"<<endl;
	for(int r=0; r<N; r++)
	{
		for(int c=0; c<N; c++)
	    cout<<m[r][c]<<" ";
	    
	    cout<<endl;
	}
}

int no_of_candidates(int row,int col,int m[N][N])
{
   int n = 0; 
   bool possible[10];
   for(int i=0; i<=9; i++)
   possible[i] = false;
   
   possible_values(row,col,m,possible);
   
   for(int i=1; i<=9; i++)
   if(possible[i] == true)
   n++;
   
   return n;
}

int constrained_selection(int &row,int &col,int m[N][N])
{
	int n;
	int min = 9;
	for(int r=0; r<N; r++)
	for(int c=0; c<N; c++)
	if(m[r][c] == 0)
	{
	    n = no_of_candidates(r,c,m);
	    if(min > n)
	    {
	    	min = n;
	    	row = r;
	    	col = c;
		}
	}
	
	return min;
}
bool next_square(int &row,int &col, int m[N][N])
{
	for(int r=0; r<N; r++)
	for(int c=0; c<N; c++)
	if(m[r][c] == 0)
	{
		row = r;
		col = c;
		return true;
	}
	
	return false;
}
void look_ahead(int row,int col,int m[N][N],bool possible[])
{
	possible_values(row,col,m,possible);
	
	for(int i=1; i<=9;i++)
	if(possible[i] == true)
	{
		int x,y;
		m[row][col] = i;
		int n = constrained_selection(x,y,m);
		
		if(n == 0)
		possible[i] = false;
		
		m[row][col] = 0;
	}
}
void possible_values(int row,int col,int m[N][N],bool possible[])
{
	int sr = row - row%3;
	int sc = col - col%3;

	for(int num = 1; num <= N; num++)
	{
		bool r = usedinrow(row,num,m);
	    bool c = usedincol(col,num,m);
	    bool b = usedinbox(sr,sc,num,m);
	
		if(!r && !c && !b)
		possible[num] = true;
	}
}

bool usedinrow(int row,int num,int m[N][N])
{
	for(int c=0; c<N; c++)
	if(m[row][c] == num)
	return true;
	
	return false;
}

bool usedincol(int col,int num,int m[N][N])
{
	for(int r=0; r<N; r++)
	if(m[r][col] == num)
	return true;
	
	return false;
}

bool usedinbox(int startrow,int startcol,int num,int m[N][N])
{
	for(int r=0; r<3; r++)
	for(int c=0; c<3; c++)
	if(m[r+startrow][c+startcol] == num)
	return true;
	
	return false;
}

void construct_candidate(vp &a,int k,int m[N][N],int c[],int &ncandidate)
{
	int row,col;
	bool possible[N+1];
	for(int i=0; i<=N;i++)
	possible[i] = false;
	
	constrained_selection(row,col,m);
	a[k].first = row;
	a[k].second = col;
	 
	possible_values(row,col,m,possible);

	ncandidate = 0;
	for(int i=1; i<= N; i++)
	{
		if(possible[i] == true)
		{
			c[ncandidate] = i;
			ncandidate++;
		}
	}
}

void make_move(vp &a,int m[N][N],int k,int value)
{
		
	int row = a[k].first;
	int col = a[k].second;

	m[row][col] = value;
 
}

void unmake_move(vp &a,int m[N][N],int k)
{
 
	int row = a[k].first;
	int col = a[k].second;
		
	m[row][col] = 0;
}

void backtrack(vp &a,int k,int m[N][N],bool &finished)
{
	int c[9];
	int ncandidate;
	
	if(is_a_solution(m))
	{
		process_solution(m);
		finished = true;
	}
	
	else
	{
		k = k + 1;
		construct_candidate(a,k,m,c,ncandidate);
		
		for(int i=0; i<ncandidate; i++)
		{
			make_move(a,m,k,c[i]);
			backtrack(a,k,m,finished);
			
			if(finished == true)
			return;
			
			unmake_move(a,m,k);
		}
	}
}

void read_matrix(int m[N][N])
{
	cout<<"enter matrix"<<endl;
	
	for(int r=0; r<N; r++)
	{
		cout<<"enter row "<<r<<endl;
		for(int c=0; c<N; c++)
		cin>>m[r][c];	
	}
}

void sudoku()
{
	int m[N][N];
	vp a(N*N +10);
	bool finished = false;
	read_matrix(m);
	backtrack(a,0,m,finished);
}

int main()
{
	sudoku();
//hard problem	
/*	                0 0 0 0 0 0 0 1 2 
					0 0 0 0 3 5 0 0 0 
					0 0 0 6 0 0 0 7 0 
					7 0 0 0 0 0 3 0 0 
					0 0 0 4 0 0 8 0 0 
					1 0 0 0 0 0 0 0 0 
					0 0 0 1 2 0 0 0 0 
					0 8 0 0 0 0 0 4 0 
					0 5 0 0 0 0 6 0 0    */
// easy problem					
/*					3 0 6 5 0 8 4 0 0 
					5 2 0 0 0 0 0 0 0 
					0 8 7 0 0 0 0 3 1 
					0 0 3 0 1 0 0 8 0 
					9 0 0 8 6 3 0 0 5 
					0 5 0 0 9 0 6 0 0 
					1 3 0 0 0 0 2 5 0 
					0 0 0 0 0 0 0 7 4 
					0 0 5 2 0 6 3 0 0  */
					
					 
	return 0;
}
