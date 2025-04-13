#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT {
    int n;
    cin >> n;
    
    int res = LLONG_MAX;
    int target = n - 3;
    for (int d = 1; d * d <= target; d++) {
        if (target % d == 0) {
            if (n % d == 3) res = min(res, d);
            if (n % (target / d) == 3) res = min(res, target / d);
        }
    }

    if (res != LLONG_MAX) cout << res << endl;

    return 0;
}
