#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

vector<int> sol(int n, int m, vector<pair<int, int>> ops, int q, vector<int> queries) {
    vector<int> coin(n + 1, 0);

    for (auto op : ops) {
        coin[op.first - 1] += 1;
        if (op.second < n) {
            coin[op.second] -= 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        coin[i] += coin[i - 1];
    }

    vector<int> res;
    for (int X : queries) {
        int cnt = 0;
        for (int c : coin) {
            if (c >= X) {
                cnt++;
            }
        }
        res.push_back(cnt);
    }

    return res;
}

int main() {
	freopen("PIGBANK.inp", "r", stdin);
	freopen("PIGBANK.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; 
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int q; 
    cin >> q;
    vector<int> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }

    vector<int> results = sol(n, m, a, q, query);

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
