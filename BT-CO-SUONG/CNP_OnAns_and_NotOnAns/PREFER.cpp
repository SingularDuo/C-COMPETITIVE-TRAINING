#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("PREFER.inp", "r", stdin);
    freopen("PREFER.OUT", "w", stdout);
    fast;
}
int main() {
    //init();
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    while (q--) {
        long long si, fi;
        cin >> si >> fi;
        auto it1 = lower_bound(a.begin(), a.end(), si);
        auto it2 = upper_bound(a.begin(), a.end(), fi);
        cout << distance(it1, it2) << '\n';
    }

    return 0;
}
