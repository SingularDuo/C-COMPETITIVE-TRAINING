#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n, m, k;
    cin >> m >> n >> k;

    char a[m + 1][n + 1];

    char f[m * k + 1][n * k + 1]; 

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) { 
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    f[(i - 1) * k + x + 1][(j - 1) * k + y + 1] = a[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= m * k; i++) {
        for (int j = 1; j <= n * k; j++) {
            cout << f[i][j];
        }
        cout << endl;
    }

    return 0;
}
