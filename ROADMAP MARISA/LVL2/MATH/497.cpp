 // Problem: Nearest Element // Contest: MarisaOJ - Basic number theory 
 // URL: https://marisaoj.com/problem/497 
 // Memory Limit: 256 MB 
 // Time Limit: 1000 ms 
 // Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

const int MAXN = 1e6;
bool isprime[MAXN + 5];

void sieve()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}

vector<ll> pttsnt(int x)
{
    vector<ll> res;
    for (int i = 2; i * i <= x; i++)
    {
        if (!isprime[i])
            continue;
        while (x % i == 0)
        {
            x /= i;
            res.push_back(i);
        }
    }
    if (x > 1)
        res.push_back(x);
    return res;
}

signed main()
{
    sieve();

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    const int MAXP = 1e3;  
    vector<vector<int>> pos(MAXP);

    for (int i = 0; i < n; i++)
    {
        vector<ll> curr = pttsnt(a[i]);
        for (int j = 0; j < curr.size(); j++)
        {
            if (curr[j] < MAXP) 
                pos[curr[j]].push_back(i);
        }
    }

    vector<int> res(n, -1);
    
    for(int i = 0; i < n; i++)
    {
    	ll suit = LLONG_MAX;
    	ll track = LLONG_MAX;
    	for(int j = 0; j < MAXP; j++)
    	{
    		if(!pos[j].empty())
    		{
    			if(i == 0)
    			{
    				ll v = pos[j][i+1] - pos[j][i];
    				if(v < track)
    				{
    					track = v;
    					suit = pos[j][i+1];
    				}
    			}
    			else
    			{
    				ll v = pos[j][i+1] - pos[j][i];
    				ll v2 = pos[j][i] - pos[j][i-1];
    				if(v < track)
    				{
    					track = v;
    					suit = pos[j][i+1];
    				}
    				if(v2 < track)
    				{
    					track = v;
    					suit = pos[j][i+1];
    				}
    			}
    		}
    	}
    	res.push_back(suit);
    }


    for (int i = 0; i < n; i++)
        cout << res[i] << " ";

    return 0;
}

