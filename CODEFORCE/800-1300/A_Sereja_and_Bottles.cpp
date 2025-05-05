#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int maxn = 1e3;

void sol() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<int> danhdau(maxn, 0);
    
    for(int i = 0; i < n; i++) {
        danhdau[a[i].second]++;
    }
    
    cout<<endl;
    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(danhdau[a[i].first] == 0 || a[i].second == a[i].first) {
            cout <<a[i].first<<" "<< danhdau[a[i].second] << endl;  
            res++;
        }
    }

    cout << res << endl;
}

int main() {
    fast;
    bool multitest = false;

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
