#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cnt = 0;
        int max_current = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>= max_current){
                cnt++;
                max_current = a[i];
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
