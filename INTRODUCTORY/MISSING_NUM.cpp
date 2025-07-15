#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    int n;
    cin>>n;
    vector<ll> a(n-1);
    for(int i = 0; i < n-1; i++)cin>>a[i];
    sort(a.begin(), a.end(), greater<ll>());
    int sub = n;
    for(int i = 0; i < sub; i++)
    {
        if(a[i] != n)
        {
            cout<<n;
            return 0;
        }
        n--;
    }
    return 0;
}
