#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void init() {
    freopen("TUYETCHIEU.inp", "r", stdin);
    freopen("TUYETCHIEU.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    ll n, k;
    cin >> n >> k;

    vector<int> a(n + 1); 
    vector<vector<int>> b(1e5 + 1); 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i); 
    }

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        for (size_t j = 0; j < b[val].size(); j++) {
            int pos = b[val][j];
            if (pos > i && pos < i + k) { 
                if (a[i] == a[pos]) { 
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }

    cout << "-1";
    return 0;
}
