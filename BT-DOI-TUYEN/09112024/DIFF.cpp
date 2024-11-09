#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll changes = n - m;
        sort(a.begin(), a.end());
        ll tongnho = 0;
        for (int i = 0; i < changes; i++)tongnho += a[i];
        ll tonglon = 0;
        for (int i = n - 1; i >= n - changes; i--)tonglon += a[i];
        cout << tonglon - tongnho << endl;
    }

    return 0;
}
