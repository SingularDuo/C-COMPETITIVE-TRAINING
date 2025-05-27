#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    fast;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &v : a) cin >> v;

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    int res = 0;

    while (i <= j) {
        if (a[i] + a[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        res++; 
    }

    cout << res << endl;
    return 0;
}
