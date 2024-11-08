#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int minn = min_element(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first < p2.first;
    })->first;
    int maxx = max_element(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    })->second;
    vector<int> luu(maxx + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = a[i].first; j < a[i].second; j++) {
            luu[j] = 1;
        }
    }
    ll max_lam = 0, max_kolam = 0;
    ll current_lam = 0, current_kolam = 0;
    for (int i = minn; i < maxx; i++) {
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
