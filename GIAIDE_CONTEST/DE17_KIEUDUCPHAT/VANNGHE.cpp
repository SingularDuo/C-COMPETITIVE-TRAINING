#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18

struct art {
    int start, end, cost;
};

signed main() {
    int n, m;
    cin >> n >> m;

    vector<art> arts(m);
    for (int i = 0; i < m; i++) {
        cin >> arts[i].start >> arts[i].end >> arts[i].cost;
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0; // bắt đầu từ thời điểm 0

    for (int i = 0; i <= n; i++) {
        if (dp[i] == INF) continue;

        for (auto& a : arts) {
            if (a.start == i && a.end <= n) {
                dp[a.end] = min(dp[a.end], dp[i] + a.cost);
            }
        }
    }

    if (dp[n] == INF) cout << -1 << endl;
    else cout << dp[n] << endl;
}
