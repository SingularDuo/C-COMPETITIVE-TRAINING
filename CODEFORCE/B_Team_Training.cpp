#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //hahahahahahahha
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;

        sort(a.begin(), a.end());
        int count = 0, res = 0;

        for (int i = n - 1; i >= 0; i--) {
            count++;
            if (a[i] * count >= x) {
                res++;
                count = 0;
            }
        }

        cout << res << endl;
    }
}