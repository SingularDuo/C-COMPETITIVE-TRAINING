#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define si size()
#define pb push_back()
#define po pop_back()
#define int long long
#define min(a,b) min((ll)a, (ll)b)
signed main()
{
    string s;
    cin>>s;
    int m;
    cin>>m;
    //sub 1
    int first = stoll(s);
    if(first % m == 0)
    {
        cout<<0;
        return 0;
    }
    bool app = false;
    ll v1 = LLONG_MAX, v2 = LLONG_MAX;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            string sub = s;
            swap(sub[i], sub[j]);
            ll num = stoll(sub);
            //cout<<num<<endl;
            if(num % m == 0)
            {
                app = true;
                v1 = min(v1, s.size() - j - 1);
                v2 = min(v2, s.size() - i - 1);
                //cout<<num<<endl;
                //return 0;
            }
        }
    }
    if(app)
    {
        cout<<1<<" "<<v1<<" "<<v2;
        return 0;
    }
    cout<<"-1 ";
    return 0;
}
//fsdfsd