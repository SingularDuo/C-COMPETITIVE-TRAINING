#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
bool multitest = false;

void sol()
{
    int n;
    cin >> n;
    vec(ll, a, n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1;
        return;
    }
    if(n == 2)
    {
        cout<<abs(a[0]-a[1]);
        return;
    }
    if(n % 2 == 0)
    {
        // tim cach chia day ban dau thanh n/2 day sao cho max(abs(a[i] - a[j])) la nho nhat
        int res = LLONG_MIN;
        for(int i = 1;i < n;i+=2)
        {
            res = max(res, abs(a[i-1] - a[i-2]));
        }
        cout<<res;
    }


}

KING_PHAT
{
    // set state for multitest
    
    multitest = true;
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
            cout << endl;
        }
    } else {
        sol();
        cout << endl;
    }
    return 0;
}