#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,pair<int,int>>> vp;

class union_find
{
	vector<int> set;

public:

	union_find(int n) : set(n,-1) {};

	int find(int x)
	{
		if(set[x] < 0)
			return x;

		return set[x] = find(set[x]);
	}

	bool _union(int a, int b)
	{
		a = find(a);
		b = find(b);

		if(a == b)
			return false;

		if(set[a] < set[b])
			set[b] = a;

		else
		{
			if(set[a] == set[b])
				set[b]--;

			set[a] = b;
		}

		return true;
	}
};

void kruskal(vp &edge,int e)
{
	int mst_weight = 0;
	
    union_find uf(e+2);
    
    sort(edge.begin(),edge.end());
    
    cout<<"edges of MST : "<<endl;
    
    for(auto i : edge)
    {
    	int w = i.first;
    	int u = i.second.first;
		int v = i.second.second;
		
		if(uf._union(u,v))
		{
	        cout<<u<<" "<<v<<" "<<w<<endl;
			
			mst_weight += w;
		}
	}

	cout<<"mst weight : "<<mst_weight<<endl; 
}

int main()
{
	int e;
	cout<<"enter no of edges"<<endl;
	cin>>e;
	
	vp edge;
	
	for(int i =0 ; i< e; i++)
	{
		int u,v,w;
		cout<<"enter edge"<<endl;
		cin>>u>>v>>w;
		edge.push_back({w,{u,v}});
	}
	 
	 kruskal(edge,e);
	
	return 0;
}

