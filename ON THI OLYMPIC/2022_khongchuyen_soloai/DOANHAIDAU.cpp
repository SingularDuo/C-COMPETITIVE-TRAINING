#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll n;
vector<ll> a;

bool dauduoi(ll l, ll r) {
    ll maxx = *max_element(a.begin() + l, a.begin() + r + 1);
    ll minn = *min_element(a.begin() + l, a.begin() + r + 1);
    return (a[l] == minn && a[r] == maxx);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dauduoi(i, j)){
                cnt++;
                cout<<a[i]<<" "<<a[j]<<endl;
            } 
        }
    }

    cout << cnt;
    return 0;
}
