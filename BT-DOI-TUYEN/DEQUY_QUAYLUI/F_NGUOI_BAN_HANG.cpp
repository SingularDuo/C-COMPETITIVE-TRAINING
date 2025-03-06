#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, S;
vector<int> w, v;
int best_value = 0;

void solve(int i, int current_weight, int current_value) {
    if (current_weight > S) return;
    if (i == n) {
        best_value = max(best_value, current_value);
        return;
    }
    solve(i + 1, current_weight, current_value);
    solve(i + 1, current_weight + w[i], current_value + v[i]);
}

KING_PHAT {
    fast;
    cin >> n >> S;
    w.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    solve(0, 0, 0);
    cout << best_value << endl;
}
