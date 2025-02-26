#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n, m, k, x;
vector<string> replacee(m);

void gen(string s, ll add) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') ret++;
    }
    if (ret == 0) {
        cout << s << endl;
        return;
    }

    for (int i = add; i < n; i++) {
        if (s[i] == '#') {
            for (char c : replacee[ret - 1]) {
                s[i] = c;
                gen(s, i + 1);
                s[i] = '#';
            }
            break;
        }
    }
}

void sol() {
    cin >> n >> m >> k >> x;
    string s;
    cin >> s;
    cin.ignore();
    replacee.resize(m);
    for (int i = 0; i < m; i++) cin >> replacee[i];

    gen(s, 0);
    return;
}

signed main() {
    sol();
    return 0;
}
