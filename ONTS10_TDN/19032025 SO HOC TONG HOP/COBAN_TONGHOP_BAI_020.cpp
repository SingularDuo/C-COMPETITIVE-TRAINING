#include <bits/stdc++.h>
using namespace std;
#define int long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x2 - x1), abs(y2 - y1)) << endl;
}
