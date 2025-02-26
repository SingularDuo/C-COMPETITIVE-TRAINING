#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()

void init()
{
    freopen("MINGROUP1.inp", "r", stdin);
    freopen("MINGROUP1.out", "w", stdout);
    if (!stdin || !stdout) {
        cerr << "Error opening file\n";
        exit(1);
    }
    faster;
}

KING_PHAT {
    init();
    ll n;
    cin >> n;
    

    vector<ll> a;
    a.reserve(n); 
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
        if (x == 1) cnt++;
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (a[i] == 0);
    }

    ll min_change = LLONG_MAX, pos1 = 0, pos2 = 0;
    for (int i = 0; i <= n - cnt; i++) { 
        ll cntz = prefix[i + cnt] - prefix[i]; 
        if (cntz < min_change) {
            min_change = cntz;
            pos1 = i;
            pos2 = i + cnt - 1;
        }
    }
    if(min_change == LLONG_MAX) min_change = -1;
    cout << min_change << endl;
}
