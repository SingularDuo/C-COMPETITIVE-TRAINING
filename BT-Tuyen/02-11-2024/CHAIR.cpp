#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll cach = n - 1;
    if (n == 2) {
        cout << "1" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    ll cnt = 0; 
    ll i = 0;
    while (cach > 0 && i < n) {
        if (a[i] <= cach) {
            cnt+=a[i];
            cach -= a[i]+1;
        } else {
            cnt++;
            cach--;
        }
        i++;
    }
    cout << cnt << endl;
    return 0;
}
