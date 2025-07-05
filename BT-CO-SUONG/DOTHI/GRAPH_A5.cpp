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
 * Generated on: 2025-06-24 09:23:43
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
    freopen("GRAPH_A5.INP", "r", stdin);
    freopen("GRAPH_A5.OUT", "w", stdout);
    fast;
}

const int MAXN = 105;

__TOISETHIVOI__ {
    init();

    int n;
    cin >> n;
    cin.ignore(); 

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        string line;
        if (!getline(cin, line)) line = "";
        stringstream ss(line);
        int v;
        while (ss >> v) {
            mat[i][v] = 1;
            mat[v][i] = 1; 
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
