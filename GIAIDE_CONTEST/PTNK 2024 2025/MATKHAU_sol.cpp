#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long
#define fi first
#define se second


int calc_digit(ll x)
{
    int res = 0;
    for(int i = 1; i <= x; i *= 10)
    {
        res += (x - i + 1);
    }
    return res;
}

const ll low_limit = 1;
const ll high_limit = 1e14;

signed main()
{
    ll k;
    cin >> k;

    ll l = low_limit, r = k, x = 0;
    while (l <= r)
    {
        
        ll mid = (l + r) / 2;
        //cout<<"mid: "<<mid<<" left: "<<l<<" right: "<<r<<endl;
        //cout<<"mid "<<mid<<endl;
        if (calc_digit(mid) < k)
            l = mid+1 ;
        else
        {
            r = mid-1;
            x = mid;
        }
    }
    //cout<<x<<endl;
    ll value = calc_digit(x - 1);
    //cout<<value<<endl;
    string s = to_string(x) + to_string(x+1) + to_string(x+2) + to_string(x+3);

    //cout<<s<<endl;

    int index = k - value - 1;
    //cout<<index<<endl;
    
    cout<<s[index]<<s[index+1]<<s[index+2]<<s[index+3];

    return 0;
}
