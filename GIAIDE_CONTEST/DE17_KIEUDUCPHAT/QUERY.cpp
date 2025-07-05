#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXn = 1e5 + 5;

void init()
{
    freopen("QUERY.INP", "r", stdin);
    freopen("QUERY.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, q;
long long a[MAXn];


long long st[4 * MAXn], lazy[4 * MAXn];


void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}


void push(int id, int l, int r) {
    if (lazy[id] != 0) {
        int mid = (l + r) / 2;
        st[id * 2] += lazy[id] * (mid - l + 1);
        st[id * 2 + 1] += lazy[id] * (r - mid);
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }
}


void update(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id] += val * (r - l + 1);
        lazy[id] += val;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    push(id, l, r);
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

signed main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pi, mi, xi;
            cin >> pi >> mi >> xi;
            update(1, 1, n, pi, mi, xi);
        } else {
            int ui, vi;
            cin >> ui >> vi;
            cout << query(1, 1, n, ui, vi) << '\n';
        }
    }

    return 0;
}
