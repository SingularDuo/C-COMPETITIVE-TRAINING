#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int main() {
    init();
    int n, k;
    cin >> n >> k;
    int a[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int f[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    int maxx = INT_MIN, first = 0, sec = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            int sun = f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k];
            if (sun > maxx) {
                maxx = sun;
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
