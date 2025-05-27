#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long


int tong_uoc(int x)
{
	ll res = 0;
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			res += i;
			if(i != x/i)res+= x/i;
		}
	}
	return res;
}
signed main()
{
	freopen("ANHEM.inp", "r", stdin);
	freopen("ANHEM.out", "w", stdout);
	
	int a, b; cin>>a>>b;
	if(tong_uoc(a) == tong_uoc(b))
	{
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	
}