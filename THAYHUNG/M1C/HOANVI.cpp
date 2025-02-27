#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
#define faster ios_base::syn_with_stdio(0) cin.tie(0) cout.tie(0);
#define King signed main()
King
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    bool able = true;
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1] + 1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}