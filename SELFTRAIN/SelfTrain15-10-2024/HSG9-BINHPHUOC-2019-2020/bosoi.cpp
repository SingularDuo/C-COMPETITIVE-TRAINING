#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("bosoi.inp", "r", stdin);
    freopen("bosoi.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    ll n, m, k;
    ll a[101][101] = {0};
    ll s;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) {
        a[i][1] = i;
        a[i][2] = i;
    }
    for (int i = 3; i <= n; i++) {
        a[1][i] = a[1][i - 1] * 2;
    }
    for (int i = 2; i <= k; i++) {
        s = i * 2;
        for (int j = 3; j <= n; j++) {
            a[i][j] = s + a[i - 1][j];
            s = s + a[i][j];
        }
    }
    cout << a[k][m] << endl;

    return 0;
}
