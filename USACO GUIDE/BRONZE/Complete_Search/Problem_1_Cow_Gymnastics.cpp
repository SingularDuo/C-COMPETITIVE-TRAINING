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
 * Generated on: 2025-07-02 16:01:33
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
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n, k; cin>>k>>n;
    vector<vector<int>> a(n + 1);
    for(int i = 0; i <k; i++)
    {
        for(int i = 1; i <= n; i++)
        {
            int c; cin>>c;
            a[c].pb(i);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            bool consistent = true;
            int dir = -1;
            for(int l = 0; l < k; l++)
            {
                if(a[i][l] < a[j][l])
                {
                    if(dir == -1) dir = 1;
                    else if(dir != 1)
                    {
                        consistent = false;
                        break;
                    }
                }
                else
                {
                    if(dir == -1) dir = 2;
                    else if(dir != 2)
                    {
                        consistent = false;
                        break;
                    }
                }
            }
            if(consistent) res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
