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
 * Generated on: 2025-07-02 15:47:22
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

const int MAXN = 205;

int n;
struct Soldier {
    int x, y, p;
}a[MAXN];

bool hear(Soldier &u, Soldier &v) {
    int dx = u.x - v.x;
    int dy = u.y - v.y;
    return dx * dx + dy * dy <= u.p * u.p;
}

int bfs(int start) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if (!visited[v] && hear(a[u], a[v])) {
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }

    return cnt;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].p;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, bfs(i));
    }

    cout << res << endl;
    return 0;
}
