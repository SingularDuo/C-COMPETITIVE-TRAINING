#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

string a, b;
map<string, int> cnt;
void gen(string &s, string &current, ll idx, int type) {
    if (!current.empty()) {
        cnt[current] += type;
    }
    for (int i = idx; i < s.size(); i++) {
        current += s[i];
        gen(s, current, i + 1, type);
        current.pop_back();
    }
}

KING_PHAT {
    fast;
    cin >> a >> b;
    
    string current = "";
    gen(a, current, 0, 1);
    current = "";
    gen(b, current, 0, 2);
    
    ll res = 0;
    for (auto &i : cnt) {
        if (i.second >= 3) { 
            res = max(res, (ll)i.first.size());
        }
    }
    cout << res << endl;
}
