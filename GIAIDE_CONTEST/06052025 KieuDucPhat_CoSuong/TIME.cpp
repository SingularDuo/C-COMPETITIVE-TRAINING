#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
#define pb push_back
#define min(a, b) min((ll)a, ll(b))
#define max(a, b) max((ll)a, ll(b))
#define __gcd(a, b) __gcd((ll)a, ll(b))

void init()
{
    freopen("TIME.INP", "r", stdin);
    freopen("TIME.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
string my_fill(string s, int n)
{
    while(s.size()<n)
    {
        s = "0"+s;
    }
    return s;
}
signed main()
{
    init();
    int n;
    cin>>n;
    vector<pair<int, pair<int, int>>> a(n);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        int f, second, t;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j]==':')
            {
                f = j;
                break;
            }
        }
        for(int j = f+1; j < s.size(); j++)
        {
            if(s[j]==':')
            {
                second = j;
                break;
            }
        }
        t = s.size();
        string s1, s2, s3;
        s1 = s.substr(0, f);
        s2 = s.substr(f+1, second-f-1);
        s3 = s.substr(second+1, t-second-1);
        
        a[i].first = stoll(s1);
        a[i].second.first = stoll(s2);
        a[i].second.second = stoll(s3);
    }
    sort(a.begin(), a.end());
    for(auto i : a)
    {
        string minute = my_fill(to_string(i.second.first), 2);
        string seconds = my_fill(to_string(i.second.second), 2);
        cout<<i.first<<":"<<minute<<":"<<seconds<<endl;
    }
}
