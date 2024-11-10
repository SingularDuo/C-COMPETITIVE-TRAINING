#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i = 0; i < n; ++i) {
        int b;
        cin>>b;
        a.push_back(abs(b));
    }
    sort(a.begin(), a.end(),greater<int>());
    cout<<a[0]<<" "<<a[1]<<" "<<a[n]<<endl;
    cout<<a[0]+a[1] - a[n];
    return 0;
}
