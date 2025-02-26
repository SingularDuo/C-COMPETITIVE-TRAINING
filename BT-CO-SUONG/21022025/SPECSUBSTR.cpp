#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()
vector<char> nguyenam = {'a','e','i','o','u'};
vector<char> phuam = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
void init()
{
    freopen("SPECSUBSTR.INP","r",stdin);
    freopen("SPECSUBSTR.OUT","w",stdout);
    faster;
}
KING_PHAT {
    init();
    string s;
    cin>>s;
    vector<int> cntnguyen(s.size(),0);
    vector<int> cntphuam(s.size(),0);
    ll cntam = 0, cntph = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(find(nguyenam.begin(),nguyenam.end(),s[i]) != nguyenam.end())
        {
            cntnguyen[i] = 1;
            cntam++;
        }
        else
        {
            cntphuam[i] = 1;
            cntph++;
        }
    }
    cout<<cntam*cntph;
    
}

/*
7
1 2 4 5 8 3 12
*/