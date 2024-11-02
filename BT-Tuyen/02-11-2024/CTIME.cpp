#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int minn = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i < n; i++) {
        minn = min(minn, a[i].first);
        maxx = max(maxx, a[i].second);
    }
    vector<int> luu(maxx + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = a[i].first; j < a[i].second; j++) {
            luu[j] = 1;
        }
    }
    ll max_lam = 0, max_kolam = 0;
    ll current_lam = 0, current_kolam = 0;
    for (int i = min_start; i < max_end; i++) {
        if (luu[i] == 1) {
            current_lam++;
            max_lam = max(max_lam, current_lam);
            current_kolam = 0;
        } else {
            current_kolam++;
            max_kolam = max(max_kolam, current_kolam);
            current_lam = 0;
        }
    }
    cout<<max_lam << endl;
    cout<<max_kolam << endl;

    return 0;
}
/*
3
100 120
150 400
500 1200
*/
/*
5
3 8
2 5
9 12
19 24
1 4
*/
