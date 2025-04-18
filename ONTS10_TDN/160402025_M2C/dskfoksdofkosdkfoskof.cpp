#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    string s;
    getline(cin, s);
    ll i = 0;
    while(s[i] == ' ')
    {
        i++;
    }
    string sb = " ";
    for(int j = i; j <s.size(); j++)
    {
        if(s[j] == ' ' && s[j+1] == ' ')
        {
            continue;
        }
        sb = sb + s[j];
    }
    sb[0] = toupper(sb[0]);
    for(int j = 1; j < sb.size(); j++)
    {
        sb[j] = tolower(sb[j]);
    }
    cout<<sb;
}