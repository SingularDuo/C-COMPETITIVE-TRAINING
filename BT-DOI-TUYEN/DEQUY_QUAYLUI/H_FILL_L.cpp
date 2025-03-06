#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;
vector<vector<ll>> a;

void fill_L1(ll x, ll y) {
    a[x][y] = 2;
    a[x][y+1] = 2;
    a[x-1][y] = 2;
}
void unfill_L1(ll x, ll y) {
    a[x][y] = 1;
    a[x][y+1] = 1;
    a[x-1][y] = 1;
}
void fill_L2(ll x, ll y) {
    a[x][y] = 2;
    a[x-1][y] = 2;
    a[x][y-1] = 2;
}
void unfill_L2(ll x, ll y) {
    a[x][y] = 1;
    a[x-1][y] = 1;
    a[x][y-1] = 1;
}
bool validcell(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool ava = false;

void gen(ll cnt) {
    if (ava) return;
    if (cnt == 0) {
        ava = true;
        return;
    }
    if (cnt < 3) return;
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (validcell(x, y) && validcell(x-1, y) && validcell(x, y+1) && a[x][y] == 1 && a[x-1][y] == 1 && a[x][y+1] == 1) {
                fill_L1(x, y);
                gen(cnt - 3);
                unfill_L1(x, y);
            }
            if (validcell(x, y) && validcell(x-1, y) && validcell(x, y-1) &&a[x][y] == 1 && a[x-1][y] == 1 && a[x][y-1] == 1) {
                fill_L2(x, y);
                gen(cnt - 3);
                unfill_L2(x, y);
            }
        }
    }
}

signed main() {
    fast;
    cin >> n >> m;
    a.resize(n, vector<ll>(m));
    ll cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char s;
            cin >> s;
            if (s == '#') a[i][j] = -1;
            else {
                a[i][j] = 1;
                cnt++;
            }
        }
    }
    
    if (cnt % 3 != 0) {
        cout << "NO";
        return 0;
    }
    
    gen(cnt);
    cout << (ava ? "YES" : "NO");
}
