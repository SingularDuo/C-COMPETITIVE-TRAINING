#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, b;
int a[300005];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> b;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == b) pos = i;
    }

    map<int, int> cnt;
    int sum = 0;
    cnt[0] = 1;

    for (int i = pos - 1; i >= 0; i--) {
        if (a[i] > b) sum++;
        else sum--;
        cnt[sum]++;
    }

    int res = 0;
    sum = 0;
    for (int i = pos; i < n; i++) {
        if (a[i] > b) sum++;
        else if (a[i] < b) sum--;

        res += cnt[-sum];
    }

    cout << res << "\n";
    return 0;
}
