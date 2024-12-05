#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long
#define endl "\n"

void init() {
    freopen("SEQBAL.inp", "r", stdin);
    freopen("SEQBAL.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i - 1] + a[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 3; j <= n; j += 2) {
            int currval = prefix_sum[j] - prefix_sum[i - 1];
            int soluong = j - i + 1;
            if (currval % (soluong / 2) == 0 && currval != soluong) {
                cnt = max(soluong, cnt);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
