#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) { 
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p; 
        }
    }
    if (n > 1) { 
        result -= result / n;
    }
    return result;
}
KING_PHAT
{
    fast;
    vector<ll> a(1e6, 0);
    for(int i = 0; i <= 1e6; i++)
    {
        a[i] = phi(i);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<a[n]<<endl;

    }

}