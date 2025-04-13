#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void input(int &n, int &m, int &a, int &b, vector<vector<ll>> &arr) {
    cin >> n >> m >> a >> b;
    if (a > b) swap(a, b); 

    arr.resize(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
}

void tongcot(int n, int m, const vector<vector<ll>> &arr, vector<vector<ll>> &f) {
    f.resize(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j] + arr[i][j];
        }
    }
}

ll findminn(set<ll> &sums, ll a, ll b) {
    auto it = sums.lower_bound((a + b) / 2);
    ll res = LLONG_MAX;

    if (it != sums.end()) res = min(res, abs(*it - a) + abs(*it - b));
    auto subit = it;

    if (it != sums.begin()) {
        it--;
        res = min(res, abs(*it - a) + abs(*it - b));
    }
    it = subit;
    if (it != sums.end()) {
        it++;
        res = min(res, abs(*it - a) + abs(*it - b));
    }

    return res;
}

ll sol(int n, int m, int a, int b, const vector<vector<ll>> &f) {
    ll res = LLONG_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            vector<ll> prefix(m + 1, 0);
            set<ll> sums;

            for (int k = 1; k <= m; k++) {
                ll sum = f[j][k] - f[i - 1][k]; 
                prefix[k] = prefix[k - 1] + sum; 

                sums.insert(prefix[k]); 

                if (*sums.begin() >= a && *sums.rbegin() <= b) return b - a;
                res = min(res, findminn(sums, a, b));
            }
        }
    }

    return res;
}

KING_PHAT
{
    fast;
    int n, m, a, b;
    vector<vector<ll>> arr, f;

    input(n, m, a, b, arr);
    tongcot(n, m, arr, f);
    cout << sol(n, m, a, b, f) << endl;
}
