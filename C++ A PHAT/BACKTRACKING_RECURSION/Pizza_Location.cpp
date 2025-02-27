#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<pair<ll, ll>> pizzaxy;
vector<vector<pair<ll, ll>>> pizzaloc;

void gen(ll idx, vector<pair<ll, ll>> &current, ll k) {
    if (current.size() == k) { 
        pizzaloc.push_back(current);
        return;
    }
    for (int i = idx; i < pizzaxy.size(); i++) {
        current.push_back(pizzaxy[i]); 
        gen(i + 1, current, k);
        current.pop_back();
    }
}

KING_PHAT {
    fast;
    ll k, r, m, n;
    cin >> k >> r;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        ll px, py;
        cin >> px >> py;
        pizzaxy.push_back({px, py});
    }
    
    cin >> n;
    vector<ll> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];

    vector<pair<ll, ll>> current;
    gen(0, current, k);

    vector<vector<ll>> place(2001, vector<ll>(2001, 0));

    for (auto [px, py] : pizzaxy) {
        place[px + 1000][py + 1000] = -1;
    }

    for (int i = 0; i < n; i++) place[x[i] + 1000][y[i] + 1000] = s[i];
    
    ll res = LLONG_MIN;
    
    for (auto &location : pizzaloc) {
        ll currans = 0;
        set<pair<ll, ll>> visited;
        
        for (auto coor : location) {
            ll px = coor.first + 1000;
            ll py = coor.second + 1000;
            
            for (int i = max(0LL, px - r); i <= min(2000LL, px + r); i++) {
                for (int j = max(0LL, py - r); j <= min(2000LL, py + r); j++) {
                    if ((i - px) * (i - px) + (j - py) * (j - py) <= r * r && place[i][j] != -1) {
                        if (visited.insert({i, j}).second) {
                            currans += place[i][j];
                        }
                    }
                }
            }
        }
        res = max(res, currans);
    }
    
    cout << res;
}
