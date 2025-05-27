#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

ll binpow(int a, int b)
{
	ll res = 1;
	while(b > 0)
	{
		if(b%2==1)res*=a;
		a*=a;
		b/=2;
	}
	return res;
}
const int MAX_SQUARE = 1e7;
vector<ll> a(MAX_SQUARE+1);
vector<ll> f(MAX_SQUARE+1, 0);
void preprocess()
{
	for(int i = 1; i<=MAX_SQUARE; i++)
	{
		a[i] = binpow(i, 2);
	}
	f[0] = a[0];
	for(int i = 1; i <= MAX_SQUARE; i ++)f[i] = f[i-1] + a[i];
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preprocess();
	int t;cin>>t;
	while(t--)
	{
		ll x; cin>>x;
		auto it = upper_bound(f.begin(), f.end(), x);
		it--;
		cout<<distance(f.begin(), it)<<" ";
	}
	
}

