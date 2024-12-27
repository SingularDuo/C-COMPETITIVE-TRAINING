#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"

int a[1005][1005];
int dp[1005][1005];
void init(){
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n, m;
    cin >> m >> n;
    cin.ignore();

    for (int i = 1; i <= m; i++) {
        string s;
        getline(cin, s);
        for (int k = 0; k < s.size(); k++) {
            int b = s[k] - '0';
            a[i][k + 1] = abs(b - 1);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] > 0 && dp[i][j - 1] > 0 && dp[i - 1][j - 1] > 0 && a[i][j] > 0)
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + a[i][j];
            else 
                dp[i][j] = a[i][j];
        }
    }

    ll res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            res += dp[i][j];
        }
    }
    
    cout << res;
}
