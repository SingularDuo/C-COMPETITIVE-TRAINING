#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    ll k,l1,r1,l2,r2,kk=1;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans=0;
    while(l1<=r2)
    {
        ans+=max(0ll,min(r1,r2)/kk-max(l1-1,l2-1)/kk);
        l1*=k;r1*=k;kk*=k;
        l1=min(l1,r2+1);
        r1=min(r1,r2+1);
    }
    cout << ans << endl;
}

signed main() {
    fast;
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}