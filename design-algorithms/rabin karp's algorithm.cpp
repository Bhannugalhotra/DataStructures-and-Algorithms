#include<iostream>
using namespace std;

#define r 256
#define q 101

int hashh(string key, int m);
bool check(string txt,string pat,int pos);
int rabin_karp(string txt,string pat);

int hashh(string key, int m)
{
	int h = 0;
	for(int i =0 ;i < m; i++)
	h = (h*r + key[i]) % q;
	
	return h;
}

bool check(string txt, string pat, int pos)
{
	int m = pat.length();
	int j = 0;
	
	while(j < m && txt[pos + j] == pat[j++]);
	
	if(j == m)
	return true;
	
	return false;
}

int rabin_karp(string txt, string pat)
{
	int n = txt.length();
	int m = pat.length();
	int pathash = hashh(pat,m);
	int txthash = hashh(txt,m);
	
	int rm = 1;
	for(int i = 1; i < m; i++)     // rm = r^(m-1)
	rm = (r*rm) % q;
	
	if(pathash == txthash)
	if(check(txt,pat,0))
	return 0;
	
	for(int i = m; i < n; i++)
	{
		txthash = (txthash + q - txt[i-m]*rm % q) % q;
		txthash = (txthash*r + txt[i]) % q;
		
		if(txthash == pathash)
		if(check(txt,pat,i-m+1))
		cout<<"patern found at "<<i - m +1<<endl;
	}
	
	return n;
}

int main()
{
	string txt,pat;
	
	cout<<"enter text"<<endl;
	getline(cin,txt);
	cout<<"enter pattern"<<endl;
	cin>>pat;
	
	int position = rabin_karp(txt,pat);
	cout<<position<<endl;
	
	return 0;
}
