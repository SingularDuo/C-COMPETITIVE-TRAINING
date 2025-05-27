// Problem: GCD and LCM
// Contest: MarisaOJ - Basic number theory
// URL: https://marisaoj.com/problem/501
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

ll lcm(int a, int b)
{
	return (a / __gcd(a, b))*b;
}
signed main()
{
	int u, v; cin>>u>>v;
	ll tich = u * v;
	int res = 0;
	
	for(int i = u; i <= v; i++)
	{
		int a = i;
		int b = tich/a;
		if(__gcd(a, b) == u && lcm(a, b) == v)res++;
	}
	cout<<res;
}