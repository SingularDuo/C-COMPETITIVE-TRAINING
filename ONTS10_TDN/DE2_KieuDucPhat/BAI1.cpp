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
 * Generated on: 2025-05-14 13:32:56
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
    freopen("BAI1.inp", "r", stdin);
    freopen("BAI1.out", "w", stdout);
    fast;
}
void sort(vector<vector<int>> &v) {
    vector<int> v1;
    for (auto i : v) {
        for (int j : i)v1.push_back(j);
    }
    sort(v1.begin(), v1.end());
    int k = 0;
    for (auto &i : v) {
        for (int &j : i)j = v1[k++];
    }
}
__TOISETHIVOI__ {
    init();
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)cin>>a[i][j];
    }
    sort(a);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}