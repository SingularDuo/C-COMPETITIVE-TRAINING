#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m)); 
    vector<ll> tong(n);
    vector<ll> maxval(n);

    for (ll i = 0; i < n; i++) {
        ll tongcurr = 0;
        ll currmax = INT_MIN;
        for (ll j = 0; j < m; j++) {  
            cin >> a[i][j];
            tongcurr += a[i][j];
            if (a[i][j] > currmax) currmax = a[i][j];
        }
        tong[i] = tongcurr; 
        maxval[i] = currmax;
    }

    for (ll i = 0; i < n; i++) cout << tong[i] << " "; 
    cout << endl;
    for (ll i = 0; i < n; i++) cout << maxval[i] << " ";
    cout << endl;  

    return 0;
}
