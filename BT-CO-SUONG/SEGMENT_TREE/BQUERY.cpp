#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BQUERY.INP", "r", stdin);
    freopen("BQUERY.OUT", "w", stdout);
    fast;
}
int n, q;
const int maxn = 1e5;
vector<ll> tree(1e5 * 4), lazy(1e5 * 4, 0);

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    tree[id] += lazy[id] * (r - l + 1); 
    if (l != r) {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v) { 
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    tree[id] = tree[id * 2] + tree[id * 2 + 1]; 
}

long long query(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || r < u) return 0; 
    if (l >= u && r <= v) return tree[id]; 
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v); 
}

KING_PHAT {
    init();
    fast;
    cin >> n >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}
