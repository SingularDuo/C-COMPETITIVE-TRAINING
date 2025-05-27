#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define main_fn signed main()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vec(type, v, sz, val) vector<type> v(sz, val)
#define all(v) v.begin(), v.end()
#define io(inp, out) freopen((string(inp) + ".inp").c_str(), "r", stdin); freopen((string(out) + ".out").c_str(), "w", stdout); fast_io;
#define mn(a, b) ((a < b) ? a : b) // Updated macro to handle vectors
#define mx(a, b) ((a > b) ? a : b)

bool mt = false;

int inv_parity(vector<ll> v) {
    int n = v.size();
    vector<ll> b = v;
    map<ll, int> comp;
    sort(all(b));

    for (int i = 0; i < n; ++i)
        comp[b[i]] = i;

    vector<int> bit(n + 1, 0);
    int p = 0;

    auto upd = [&](int i) {
        for (++i; i <= n; i += i & -i)
            bit[i]++;
    };

    auto qry = [&](int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    };

    for (int i = n - 1; i >= 0; --i) {
        int x = comp[v[i]];
        p ^= qry(x - 1) % 2;
        upd(x);
    }

    return p;
}

vector<ll> merge_vecs(vector<ll> ev, vector<ll> od) {
    int n = ev.size() + od.size();
    vector<ll> res(n);
    int ei = 0, oi = 0;
    for (int i = 0; i < n; ++i) {
        res[i] = (i % 2 == 0) ? ev[ei++] : od[oi++];
    }
    return res;
}

void sol() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n), e, o;
        for (ll i = 0; i < n; ++i) {
            cin >> v[i];
            (i % 2 == 0 ? e : o).push_back(v[i]);
        }

        vector<ll> se = e, so = o;
        sort(all(se));
        sort(all(so));

        ll pe = inv_parity(e);
        ll po = inv_parity(o);

        vector<ll> res;

        if (pe == po) {
            res = merge_vecs(se, so);
        } else {
            vector<ll> opt1 = se, opt2 = so;

            if (opt1.size() >= 2)
                swap(opt1[opt1.size() - 1], opt1[opt1.size() - 2]);

            if (opt2.size() >= 2)
                swap(opt2[opt2.size() - 1], opt2[opt2.size() - 2]);

            vector<ll> c1 = merge_vecs(opt1, so);
            vector<ll> c2 = merge_vecs(se, opt2);

            res = (c1 < c2) ? c1 : c2; // Proper comparison instead of the `mn` macro
        }

        for (ll x : res)
            cout << x << " ";
        cout << '\n';
    }
}

main_fn {
    fast_io;
    if (mt) {
        ll t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}
