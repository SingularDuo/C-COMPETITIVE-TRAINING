#pragma GCC optimize("O2", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 10005;
const int SHIFT = 200000;
const int MAXS = 400005;

int a[N];
int sum_cnt[MAXS];  // chỉ lưu số lượng, không lưu từng cặp

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    memset(sum_cnt, 0, sizeof(sum_cnt));

    long long res = 0;


    for (int x3 = 1; x3 <= n; x3++) {

        for (int x4 = x3 + 1; x4 <= n; x4++) {
            int need = k - a[x3] - a[x4] + SHIFT;
            if (0 <= need && need < MAXS) {
                res += sum_cnt[need];
            }
        }


        for (int i = 1; i < x3; i++) {
            int s = a[i] + a[x3] + SHIFT;
            if (0 <= s && s < MAXS) {
                sum_cnt[s]++;
            }
        }
    }

    cout << res << "\n";
    return 0;
}
