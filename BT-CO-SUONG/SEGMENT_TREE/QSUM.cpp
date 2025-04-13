#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<ll> st;
int ssize; 

void build(vector<ll>& a, int node, int start, int end) {
    if (start == end) {
        st[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(a, 2 * node + 1, start, mid);
        build(a, 2 * node + 2, mid + 1, end);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
}

void update(int idx, ll value, int node, int start, int end) {
    if (start == end) {
        st[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(idx, value, 2 * node + 1, start, mid);
        } else {
            update(idx, value, 2 * node + 2, mid + 1, end);
        }
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
}

ll query(int l, int r, int node, int start, int end) {
    if (r < start || l > end) {
        return 0;
    }
    if (l <= start && r >= end) {
        return st[node];
    }
    int mid = (start + end) / 2;
    ll ls = query(l, r, 2 * node + 1, start, mid);
    ll rs = query(l, r, 2 * node + 2, mid + 1, end);
    return ls + rs;
}

KING_PHAT
{
    freopen("QSUM.INP", "r", stdin);
    freopen("QSUM.OUT", "w", stdout);
    fast;

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n >= 1000) {
        ssize = n; 
        st.resize(4 * ssize);
        build(a, 0, 0, n - 1);
        while (q--) {
            int type, idx_1, idx_2;
            cin >> type >> idx_1 >> idx_2;
            if (type == 1) {
                idx_1--;
                update(idx_1, idx_2, 0, 0, n - 1);
            } else {
                cout << query(idx_1 - 1, idx_2 - 1, 0, 0, n - 1) << endl;
            }
        }
    } else {
        vector<ll> f(n);
        f[0] = a[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] + a[i];
        }
        while (q--) {
            int type, idx_1, idx_2;
            cin >> type >> idx_1 >> idx_2;
            if (type == 1) {
                idx_1--;
                a[idx_1] = idx_2;
            } else {
                ll sum = 0;
                for (int i = idx_1 - 1; i <= idx_2 - 1; i++) {
                    sum += a[i];
                }
                cout << sum << endl;
            }
        }
    }
}
