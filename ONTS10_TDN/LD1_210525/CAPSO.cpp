#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main()
{
	freopen("CAPSO.INP", "r", stdin);
	freopen("CAPSO.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> cnt; 
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll res = 0;

    for (int i = 0; i < n; i++) {
        int v = k - a[i];
        
        if (cnt.count(v)) { 
            res += cnt[v]; 
            
            if (v == a[i]) res--; 
        }
    }
    
    cout << res / 2 << endl; 
}
