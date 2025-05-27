#include<bits/stdc++.h>

using namespace std;

#define ll long long

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a, b; cin>>a>>b;
	
	ll res = a;
	
	res += (b/3);
	if(b%3 != 0)res++;
	cout<<res;
}