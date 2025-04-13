#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("CAMPING.INP", "r", stdin);
    freopen("CAMPING.OUT", "w", stdout);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end())
    {
        cout << n + 1;
    }
    else
    {
        cout << distance(a.begin(), it)+1;
    }
}
