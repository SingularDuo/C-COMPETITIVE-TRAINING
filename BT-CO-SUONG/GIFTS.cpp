#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio() cin.tie(0) cout.tie(0)
void init(){
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    fast;
}
signed main() {
    init();
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());
    for(int i = 0; i < n;i++)
    {
        if(a[i] > x) a[i] = -1;
    }
    
    // sub1
    if(n <= 1000)
    {
        ll maxx = LLONG_MIN;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                ll curr = a[i] + a[j];
                if(curr <= x && a[i] != -1 && a[j] != -1)
                {
                    maxx = max(maxx, curr);
                    if(maxx == x)
                    {
                        cout << maxx;
                        return 0;
                    }
                }
            }
        }
        cout << maxx;
        return 0;
    }
    ll maxx = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) continue; 
        for (int j = n - 1; j > i; j--) { 
            if (a[j] == -1) continue;

            ll current = a[i] + a[j];

            if (current > x) continue; 

            maxx = max(current, maxx);

            if (maxx == x) { 
                cout << maxx;
                return 0;
            }
        }
    }
    cout<<maxx;
}
