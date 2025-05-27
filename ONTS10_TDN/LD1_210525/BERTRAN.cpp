#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int maxn = 1e7;
bool isprime[maxn + 5];

void sieve()
{
	memset(isprime, true, sizeof(isprime));
	
	isprime[0] = isprime[1] = false;
	for(int i = 2; i * i <= maxn; i++)
	{
		if(isprime[i])
		{
			for(int j = i * i; j <= maxn; j += i)
			{
				isprime[j]=false;
			}
		}
	}
}
signed main()
{
	freopen("BERTRAN.inp", "r", stdin);
	freopen("BERTRAN.out", "w", stdout);
	
	sieve();
	
	int n; cin>>n;
	int limit = 2 * n;
	ll res = 0;
	for(int i = n+1; i < limit; i++)
	{
		if(isprime[i])
		{
			cout<<i<<" ";
			res++;
		}
	}
	cout<<endl;
	cout<<res;
	return 0;
}