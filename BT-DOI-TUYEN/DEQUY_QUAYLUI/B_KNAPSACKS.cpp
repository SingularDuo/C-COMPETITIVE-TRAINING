#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second

int main() {
    ll n, w;
    cin >> n >> w;
    
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) { 
            if (j >= a[i])         
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
            else
                f[i][j] = f[i - 1][j]; 
        }
    }

    cout << f[n][w] << endl;
    return 0;
}
