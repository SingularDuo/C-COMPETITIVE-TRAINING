#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"

void init() {
    freopen("DAPNUI.inp", "r", stdin);
    freopen("DAPNUI.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init(); 
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b = a;
    vector<ll> trai(n, 0);
    vector<ll> phai(n, 0);
    vector<ll> final(n);
    for (int peak = 1; peak < n - 1; peak++) {
        trai = vector<ll>(n, 0); 
        for (int i = peak - 1; i >= 0; i--) {
            if (a[i] >= a[i + 1]) {
                trai[i] = trai[i + 1] + (a[i] - a[i + 1] + 1);
                a[i] = a[i + 1] - 1;
            }
        }
        a = b; 
    }
    for (int peak = 1; peak < n - 1; peak++) {
        phai = vector<ll>(n, 0);  
        for (int i = peak + 1; i < n; i++) {
            if (a[i] >= a[i - 1]) {
                phai[i] = phai[i - 1] + (a[i] - a[i - 1] + 1);
                a[i] = a[i - 1] - 1;
            }
        }
        a = b; 
    }
    ll min_cost = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        final[i] = phai[i] + trai[i];
        min_cost = min(min_cost, final[i]);
    }
    
    cout << min_cost << endl;
    
    return 0;
}
