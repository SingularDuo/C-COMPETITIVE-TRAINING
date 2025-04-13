#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
