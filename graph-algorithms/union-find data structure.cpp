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
