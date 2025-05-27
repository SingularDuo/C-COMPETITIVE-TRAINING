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
 * Generated on: 2025-05-16 14:22:58
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

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;
const int NEG = -1e18;
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
    int n; cin>>n;
    vector<ll> a(n);
    
    for(int i = 0;i < n; i++)cin>>a[i];

    int minn = INF, maxx = NEG;
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
            continue;
        }
        if(a[i] < minn || a[i] > maxx)res++;
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    cout<<res;


    return 0;
}