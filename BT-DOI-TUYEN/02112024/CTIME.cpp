#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 5 * 1e6; 
int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int minn = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i < n; i++) {
        minn = min(minn, a[i].first);
        maxx = max(maxx, a[i].second - 1);
    }
    vector<int> luu(maxx + 2, 0);
    vector<int> cong(maxx + 2, 0);
    vector<int> tru(maxx + 2, 0);
    
    for (int i = 0; i < n; i++) {
        int L = a[i].first;
        int R = a[i].second;
        cong[L]++;
        tru[R]++;
    }

    luu[0] = cong[0] - tru[0];
    for (int i = 1; i <= maxx; i++) {
        luu[i] = luu[i - 1] + cong[i] - tru[i];
    }

    ll max_lam = 0, max_kolam = 0;
    ll current_lam = 0, current_kolam = 0;

    for (int i = minn; i <= maxx; i++) {
        if (luu[i] > 0) {
            current_lam++;
            max_lam = max(max_lam, current_lam);
            current_kolam = 0;
        } else {
            current_kolam++;
            max_kolam = max(max_kolam, current_kolam);
            current_lam = 0; 
        }
    }
    cout << max_lam << endl;
    cout << max_kolam<< endl;  
    return 0;
}
