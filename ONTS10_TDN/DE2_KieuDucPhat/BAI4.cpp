/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-05-14 14:35:04
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long 
#define endl "\n"
// #define min(a, b) min((ll)a, (ll)b) // std::min is fine
// #define max(a, b) max((ll)a, (ll)b) // std::max is fine
#define fi first
#define se second
#define si size() // vector.size() returns size_t.
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7; 
const ll INF = 2LL * 1000000000000000000LL; 

void init() {
    freopen("BAI4.inp", "r", stdin);
    freopen("BAI4.out", "w", stdout);
    fast;
}
vector<ll> khonggiam(const vector<ll>& arr) {
    int n_size = arr.si; 
    if (n_size == 0) return {};
    
    vector<ll> dp(n_size);
    vector<ll> track; 
    for (int i = 0; i < n_size; ++i) { 
        auto it = upper_bound(all(track), arr[i]);
        dp[i] = distance(track.begin(), it) + 1;
        
        if (it == track.end()) {
            track.pb(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    return dp;
}

__TOISETHIVOI__ {
    init();
    fast; 

    int n, m;
    cin >> n >> m;
    m = m - 1; 
    vector<ll> a(n); 
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
    }   
    vector<ll> dpl = khonggiam(a);
    vector<ll> a_rev_neg(n);
    for (int i = 0; i < n; ++i) { 
        a_rev_neg[i] = -a[n - 1 - i]; 
    }
    vector<ll> dpc = khonggiam(a_rev_neg);
    
    vector<ll> dpr(n);
    for (int i = 0; i < n; ++i) { 
        dpr[i] = dpc[n - 1 - i];
    }
    ll maxxl = 0; 

    for (int i = 0; i < m; ++i) { 
        if (a[i] <= a[m]) {
            maxxl = max(maxxl, dpl[i]);
        }
    }
    ll maxxr = 0;

    for (int i = m + 1; i < n; ++i) { 
        if (a[i] >= a[m]) {
            maxxr = max(maxxr, dpr[i]);
        }
    }
    cout << maxxl + 1 + maxxr << endl;
    
    return 0;
}