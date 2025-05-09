#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)

const int limit_sub1 = 1e6 + 5;
const int limit_val_sub1 = 1e6;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    int ss = k + 5;
    ll curr = 0;
    string s = "";
    ll i = 1;
    while(s.size() <= ss)
    {
        //cout<<i<<endl;
        s += to_string(i);
        i++;
    }
    k--;
    cout<<s[k]<<s[k+1]<<s[k+2]<<s[k+3];
    return 0;
}