#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()

int nhiphan(vector<pair<int, int>> &a, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid].fi == target) return a[mid].se; 
        if (a[mid].fi < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

KING_PHAT {
    faster;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1; 
    }
    sort(a.begin(), a.end()); 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - (a[i].fi + a[j].fi);
            int find = nhiphan(a, j + 1, n - 1, target);
            if (find != -1) {
                cout<<a[i].se <<" "<<a[j].se<<" "<<find<<"\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
