#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;

bool multitest = false;

void init() {
    // Initialize with input-output files and fast IO
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end()); 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

KING_PHAT {
    // Uncomment and set state for multitest if needed
    // multitest = true;
    // Uncomment and set state for custom input-output files if needed
    // I_O("test1", "test1");

    fast; // Ensures fast IO
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}
