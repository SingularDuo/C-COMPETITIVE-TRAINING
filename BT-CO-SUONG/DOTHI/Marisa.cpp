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
 * Generated on: 2025-07-01 16:32:42
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

const int MAX = 2e5 + 5; // vì có thể nhân 2, nên chọn lớn hơn 1e5

__TOISETHIVOI__ {
    //init();
    fast;
    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << n - m;
        return 0;
    }

    vector<int> dist(MAX, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u - 1 >= 1 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        if (u * 2 < MAX && dist[u * 2] == -1) {
            dist[u * 2] = dist[u] + 1;
            q.push(u * 2);
        }

        if (dist[m] != -1) break;
    }

    cout << dist[m];
    return 0;
}
