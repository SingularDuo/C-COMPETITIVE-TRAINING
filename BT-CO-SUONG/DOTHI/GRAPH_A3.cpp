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
 * Generated on: 2025-06-24 10:03:55
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

void init() {
  freopen("GRAPH_A3.inp", "r", stdin);
  freopen("GRAPH_A3.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n; cin>>n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<pair<ll, ll>> res;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt  = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                cnt++;
                a[i][j] = 0;
                a[j][i] = 0;
                res.push_back({i + 1, j + 1});
            }
        }
    }
    cout<<cnt<<endl;
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}
/* 
8
0 1 1 0 0 0 0 0 
1 0 1 1 0 0 0 0
1 1 0 0 1 0 0 0
0 1 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0
*/