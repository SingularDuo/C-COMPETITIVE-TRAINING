#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long


void init()
{
	freopen("Cau1b.inp", "r", stdin);
	freopen("Cau1b.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int maxP = 1e6; 
bool isprime[maxP + 3];
vector<ll> primeP;

void sieve()
{
    memset(isprime, true, sizeof(isprime));

    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= maxP; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= maxP; j += i)
            {
                isprime[j] = false; 
            }
        }
    }

    for (int i = 2; i <= maxP; i++)
    {
        if (isprime[i])
        {
            primeP.push_back(i);
        }
    }
}

const int maxD = 100;
vector<ll> primeD;
void genD()
{
	for(int i = 3; i <= maxD + 5; i ++)
	{
		if(isprime[i])primeD.push_back(i);
	}
}
ll binpow(int a, int b)
{
	ll res = 1;
	while(b > 0)
	{
		if(b % 2 == 1) res = res * a;
		a = a*a;
		b /= 2;
	}
	return res;
}
signed main()
{
	init();
	sieve();
	genD();
	int l , r; cin>>l>>r;
	
	ll res = 0;
	for(int i = 0; i < primeP.size(); i++)
	{
		if(primeP[i] > r)break;
		if(binpow(primeP[i], 2) > r)break;
		for(int j = 0; j < primeD.size(); j++)
		{
			ll v = binpow(primeP[i], primeD[j]-1);
			if(v > r)break;
			if(v >= l)
			{
				//cerr<<binpow(primeP[i], primeD[j]-1)<<endl;
				res++;
			}
			
		}
	}
	cout<<res;
	
}