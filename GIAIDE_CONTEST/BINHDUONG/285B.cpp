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
 * Generated on: 2025-05-16 14:35:51
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const ll MOD = 1e9 + 7;
const ll INF =  LLONG_MAX;

void init() {
  #ifndef ONLINE_JUDGE
    if (FILE *file = fopen("input.inp", "r")) {
      fclose(file);
      freopen("input.inp", "r", stdin);
      freopen("output.out", "w", stdout);
    }
  #endif
  fast;
}

__TOISETHIVOI__ {
    init();
    int n,s, t; cin>>n>>s>>t;
    vector<ll> move(n + 1); 
    for (int i = 1; i <= n; i++) cin >> move[i];

    if (s == t) {
        cout << 0;
        return 0;
    }

    ll cnt = 0;
    set<int> visited; 

    while (s != t) {
        if (visited.count(s)) { 
            cout << -1 << endl;
            return 0;
        }
        visited.insert(s);
        s = move[s];
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}

