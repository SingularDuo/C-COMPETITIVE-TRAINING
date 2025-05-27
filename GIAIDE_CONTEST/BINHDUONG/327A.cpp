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
 * Generated on: 2025-05-16 12:45:08
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
    for(int i = 0; i < n; i++)cin>>a[i];

    ll res = NEG;
    for(int i = 0; i < n; i++)
    {
        for(int j = i ; j < n; j++)
        {
            ll curr = 0;
            vector<ll> sub = a;
            for(int l = i; l <= j; l++)
            {
                if(a[l] == 0)
                {
                    a[l] = 1;
                }
                else a[l] = 0; 
            }
            for(int l = 0; l < n; l++)
            {
                if(a[l] == 1)curr++;
            }
            res = max(res, curr);
            a = sub;
        }
    }
    cout<<res;
    return 0;
}