#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"

void init()
{
	freopen("DAYNT.inp", "r", stdin);
	freopen("DAYNT.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int MAXN = 1e5;
bool isprime[MAXN + 5];
void sieve()
{
	memset(isprime, true, sizeof(isprime));
	
	int sqrtN = sqrt(MAXN);
	isprime[0] = isprime[1] = false;
	
	for(int i = 2; i <= sqrtN; i++)
	{
		if(isprime[i])
		{
			for(int j = i * i; j <= MAXN; j+=i)isprime[j] = false;
		}
	}
}
signed main()
{
	init();
	sieve();
	int k; cin>>k;
	vector<int> res;
	
	int a; 
	while(cin>>a)
	{
		if(isprime[a])res.push_back(a);
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < k ; i++)cout<<res[i]<<" ";
	
	
}