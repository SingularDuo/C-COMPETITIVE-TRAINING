#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    fast;
}
KING_PHAT {
    init();
    int n;
    cin >> n;
    vector<int> count(3, 0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x % 3]++;
    }
    
    int res = count[0] * (count[0] - 1) / 2 + count[1] * count[2];
    cout << res << endl;
}
