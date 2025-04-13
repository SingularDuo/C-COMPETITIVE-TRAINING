#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("SOHOC.INP", "r", stdin);
    freopen("SOHOC.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int m, n, k;
vector<int> p, q;
int p_product = 1, q_product = 1, target;
int ans = 0;

void backtrack(int idx, int cnt, int nhan) {
    if (cnt == k) {
        if (nhan == target) ans++;
        return;
    }
    if (idx >= m || nhan > target) return;
    if (target % p[idx] == 0) backtrack(idx + 1, cnt + 1, nhan * p[idx]);

    backtrack(idx + 1, cnt, nhan);
}

signed main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    p.resize(m);
    q.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p_product *= p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q_product *= q[i];
    }

    if (q_product % p_product != 0) {
        cout << 0 << endl;
        return 0;
    }

    target = q_product / p_product;
    ans = 0;
    backtrack(0, 0, 1);

    cout << ans << endl;
    return 0;
}
