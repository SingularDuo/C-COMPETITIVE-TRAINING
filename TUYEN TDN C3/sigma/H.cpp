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
 * Generated on: 2025-07-10 14:13:04
*/

#include <bits/stdc++.h>
using namespace std;

// ========== Type Aliases ==========
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

// ========== Short Macros ==========
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define si size()
#define endl "\n"

// ========== Loop Macros ==========
#define FOR(i,n)        for (int i = 0; i < n; ++i)
#define REP(i,a,b)      for (int i = a; i <= b; ++i)
#define FORD(i,a,b)     for (int i = a; i >= b; --i)
#define FORDEC(i,a,b,c) for (int i = a; i >= b; i -= c)

// ========== Fast I/O ==========
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ========== Output Shortcuts ==========
#define yes cout << "YES\n"
#define no cout << "NO\n"

// ========== Custom Macros ==========
#define __TOISETHIVOI__ signed main()
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

// ========== Debug Helper ==========
// #define debug(x) cerr << #x << " = " << x << endl;

void init() {
  freopen("H.inp", "r", stdin);
  freopen("H.out", "w", stdout);
  fast;
}

int n;
int a[505][505];
bool vis[505][505];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool bfs(int lim) {
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    q.push({0, 0});
    vis[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        if (x == n - 1 && y == n - 1) return true;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny]) continue;

            if (abs(a[nx][ny] - a[x][y]) <= lim) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

__TOISETHIVOI__ {
    init();

    cin >> n;
    FOR(i, n) FOR(j, n) cin >> a[i][j];

    int l = 0, r = 1e5, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (bfs(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans ;

    return 0;
}
