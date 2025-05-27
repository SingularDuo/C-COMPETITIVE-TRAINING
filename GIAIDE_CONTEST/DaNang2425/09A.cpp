#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long 
#define endl "\n"
#define pb push_back()

bool correct(int x)
{
    if(x == 1)return true;
    if(x < 10)return false;
    string s = to_string(x);
    int le = 0, chan = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(i % 2 == 0)chan += s[i] - '0';
        else le += s[i] - '0';
    }
    //cout<<x<<" "<<le<<" "<<chan<<endl;
    return (le - chan) == 1;
}
signed main()
{
    int l, r; cin>>l>>r;

    ll res =0;

    for(int i = l; i <= r; i++)
    {
        if(correct(i))
        {
            res++;
            
        }
    }
    cout<<res;
}