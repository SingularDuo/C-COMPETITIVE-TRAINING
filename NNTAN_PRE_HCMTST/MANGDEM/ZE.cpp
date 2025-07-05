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
 * Generated on: 2025-07-04 09:45:58
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
int n, m;
vector<vector<ll>> a;

void init() {
  fast;
}

void sub1()
{
    vector<vector<ll>> f(n + 1, vector<ll>(m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i-1][j-1];
        }
    }

    int res = 0;
    for(int x = 1; x <= n; x++)
    {
        for(int y = 1; y <= m; y++)
        {
            for(int u = x; u <= n; u++)
            {
                for(int v = y; v <= m; v++)
                {
                    ll sum_area = f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
                    if(sum_area % 9 == 0) res++;
                }
            }
        }
    }
    cout << res << endl;
}
void sub2() {
    int res = 0;

    //N, M <= 500, AIJ  = 1
    for (int height = 1; height <= n; height++) {
        for (int width = 1; width <= m; width++) {
            if ((height * width) % 9 == 0) {
                int count_height = n - height + 1;
                int count_width = m - width + 1;
                res += count_height * count_width;
            }
        }
    }

    cout << res << endl;
}
void sub3() {
    int res = 0;
    vector<int> col_sum(m);  

    for (int top = 0; top < n; top++) {
        fill(col_sum.begin(), col_sum.end(), 0);
        for (int bottom = top; bottom < n; bottom++) {

            for (int j = 0; j < m; j++) {
                col_sum[j] += a[bottom][j];
            }

            map<int, int> cnt;
            cnt[0] = 1;
            int pref = 0;
            for (int j = 0; j < m; j++) {
                pref = (pref + col_sum[j]) % 9;
                if (pref < 0) pref += 9;
                res += cnt[pref];
                cnt[pref]++;
            }
        }
    }

    cout << res << endl;
}

__TOISETHIVOI__ {
    init();
    cin >> n >> m;
    a.resize(n, vector<ll>(m));
    bool is2 = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
            if(a[i][j] != 1)is2 = false;
        }
    }
    if(n <= 90 && m <= 90)
    {
        sub1();
        return 0;
    }
    else if(is2)
    {
        sub2();
        return 0;
    }
    else sub3();
    return 0;
}
