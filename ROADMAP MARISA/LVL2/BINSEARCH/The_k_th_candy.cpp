#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

signed main() {
    fast;
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;  
    
    vector<int> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }

    sort(a.begin(), a.end());  

    vector<int> pos(n);
    pos[0] = a[0].second; 
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + a[i].second;
    }

    for (int i = 0; i < q; i++) {
        int l = 0, r = n - 1, submid = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pos[mid] < query[i]) {
                l = mid + 1;
            } else {
                submid = mid; 
                r = mid - 1;
            }
        }

        if (submid != -1) {
            cout << a[submid].first << endl; 
        }
    }

    return 0;
}
