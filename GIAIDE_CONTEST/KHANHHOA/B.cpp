#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define int long long


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin>>n;
	string s; cin>>s;


	ll cA2 = 0, cB2 = 0;
	string sub = s;
	
	
	s = sub;
	char rep = 'A';
	ll res1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '*')s[i] = rep;
	}
	cA2 = 0, cB2 = 0;
	for(int i = 0; i < s.size() - 1; i++)
	{
		if(s[i] == s[i+1])
		{
			if(s[i] == 'A')cA2++;
			else cB2++;
		}
	}
	res1 = max(cA2, cB2);
	
	s=sub;
	cA2 = 0, cB2=0;
	rep = 'B';
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '*')s[i] = rep;
	}
	cA2 = 0, cB2 = 0;
	for(int i = 0; i < s.size() - 1; i++)
	{
		if(s[i] == s[i+1])
		{
			if(s[i] == 'A')cA2++;
			else cB2++;
		}
	}
	ll res2 = max(cA2,cB2);
	cout<<max(res1,res2);
}