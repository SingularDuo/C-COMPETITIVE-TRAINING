// dung thuat toan Kadane
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int maxx(vector<int> &arr) {
    int res = arr[0];
    int maxend = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxend = max(maxend + arr[i], arr[i]);
        res = max(res, maxend);
    }
    return res;
}

signed main() {
    freopen("SUMMAX.INP", "r", stdin);
    freopen("SUMMAX.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    ll res = maxx(a);
    cout<<res;
    return 0;
}
