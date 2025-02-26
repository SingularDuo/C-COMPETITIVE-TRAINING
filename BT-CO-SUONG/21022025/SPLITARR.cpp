#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()
void init(){
    freopen("SPLITARR.INP","r",stdin);
    freopen("SPLITARR.OUT","w",stdout);
    faster;
}
KING_PHAT
{
    init();
    int n;
    cin >> n;
    vector<ll> a(n), pre(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    ll sum = pre[n];
    if (sum % 3 != 0) {
        cout << "-1\n";
        return 0;
    }

    ll part = sum / 3;
    int i = -1, j = -1;
    for (int k = 1; k < n; k++) {
        if (pre[k] == part && i == -1) i = k;
        if (pre[k] == 2 * part && i != -1) {
            j = k;
            break;
        }
    }

    if (i != -1 && j != -1) cout << i-1 << " " << j-1 << "\n";
    else cout << "-1\n";

    return 0;
}
