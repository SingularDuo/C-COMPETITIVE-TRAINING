#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

signed main()
{
    fast;
    int n;
    cin >> n;
    vector<int> a(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << 0; 
        return 0;
    }

    int part = sum / 3;
    int cnt = 0, res = 0, prefix_sum = 0;

    for (int i = 0; i < n - 1; i++) {
        prefix_sum += a[i];

        if (prefix_sum == 2 * part) {
            res += cnt; 
        }
        if (prefix_sum == part) {
            cnt++;
        }
    }

    cout << res;
}
