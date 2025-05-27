#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

const int INF = 1e18;

signed main() {
    int t; cin >> t;

    while (t--) {
        int m, x; cin >> m >> x;
        vector<pair<int, int>> a(m);
        int s = 0;
        
        for (int i = 0; i < m; i++) {
            cin >> a[i].first >> a[i].second;
            s += a[i].second;
        }
        //(dp[i]) la  tong kl cac bao boi it nhat de co gia tri phep thuat la i 
        
        vector<ll> dp(s + 1, INF);
        dp[0] = 0;  

        for (int i = 0; i < m; i++) {
            int c = a[i].first, h = a[i].second;
            int nobita = i * x;// suc manh nobita o luot i

            vector<ll> neww = dp;
            for (int j = 0; j <= s-h; j++)
            {
                if(dp[j] != INF && dp[j] + c <= nobita)
                {
                    neww[j + h] = min(neww[j + h], dp[j] + c);
                }
            }
            dp = neww;
        }

        int res = LLONG_MAX;
        for (int j = s; j >= 0; j--) {
            if (dp[j] != INF) {
                res = j;
                break;
            }
        }
        cout << res << endl;
    }
}
