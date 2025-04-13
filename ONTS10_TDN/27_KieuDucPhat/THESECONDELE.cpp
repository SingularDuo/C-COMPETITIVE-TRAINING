#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("THESECONDELE.inp", "r", stdin);
    freopen("THESECONDELE.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end(), greater<ll>());
    cout<<a[1];
    return 0;
}
