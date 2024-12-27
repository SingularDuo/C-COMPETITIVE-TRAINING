#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"

int a[1005][1005];
int dp[1005][1005];

void init() {
    freopen("MATRIX01.INP", "r", stdin);
    freopen("MATRIX01.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int n, m;
    cin >> m >> n; 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (a[i][j] == 1) ? 1 : 0;
        }
    }
    int maxx = 0; 

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int first = 0, second = 0;
            if (j > 1 && a[i][j - 1] >= 1 && dp[i][j] > 0) {
                if (dp[i][j - 1] == 1 && a[i][j] == 1) {
                    first = 2;
                } else {
                    first = dp[i][j - 1] / 3 + dp[i][j-1];
                }
            }

            if (i > 1 && a[i - 1][j] == 1 && dp[i][j] > 0) { 
                if (dp[i - 1][j] == 1 && a[i][j] == 1) {
                    second = 2;
                } else {
                    second = dp[i - 1][j] / 3 + dp[i-1][j];
                }
            }
                dp[i][j] = max({dp[i][j], first, second});
                maxx = max(maxx, dp[i][j]);
            }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {  
            cout<<dp[i][j]<<" ";
        }
        cout << endl;
    }
    cout << maxx << endl; 
    return 0;
}
