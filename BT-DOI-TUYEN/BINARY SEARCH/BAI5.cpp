#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()

KING_PHAT {
    faster;
    int n, q;
    cin>>n>>q;
    set<int> a; 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    while (q--) {
        int k, missing = 1;
        cin >> k;
        while (k > 0) {
            if (a.find(missing) == a.end()) { 
                k--; 
                if (k == 0) { 
                    cout << missing << endl;
                    break;
                }
            }
            missing++;
        }
    }

    return 0;
}
