#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> cnt(1e9);
    memset(cnt,0,sizeof(cnt));
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]];
    }
    
    return 0;
}
