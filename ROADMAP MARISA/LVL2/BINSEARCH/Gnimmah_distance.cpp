#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
string s, s1;
ll res = 0;

void sliding_window(int start, int wsize)
{
    //cout<<"size"<<start<<" "<<wsize<<endl;
    for(int i = start + wsize-1; i < s.size() - wsize; i += wsize)
    {
        ll b_idx = 0;
        for(int j = i - wsize; j <= i; j++)
        {
            if(s[j] == s1[b_idx])
            {
                res++;
                //cout<<s[j]<<" "<<s1[b_idx]<<endl;
            }
            b_idx++;
        }
    }
}

KING_PHAT
{
    fast;
    cin>>s>>s1;
    for(int i = 0; i < s1.size(); i++)
    {
        sliding_window(i, s1.size());
    }
    cout<<"res"<<res;
}