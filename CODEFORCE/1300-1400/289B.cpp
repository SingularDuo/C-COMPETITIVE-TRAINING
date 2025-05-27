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
 * Generated on: 2025-05-13 22:58:26
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

__TOISETHIVOI__ {
    //init();

    int n, m,k; cin>>n>>m>>k;
    int minn = LLONG_MAX, maxx =  LLONG_MIN;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            minn = min(minn, a[i][j]);
            maxx = max(maxx, a[i][j]);
        }
    }
    vector<vector<int>> sub = a;
    // CASE DECREASE
    bool dec = true;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
            while(a[i][j] > minn)
            {
              a[i][j] -= k;
            }
            if(a[i][j] < k)
            {
                dec = false;
                break;
              
            }
      }
    }
    return 0;
}