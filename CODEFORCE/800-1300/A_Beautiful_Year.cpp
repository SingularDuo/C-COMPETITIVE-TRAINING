#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
bool isdistinct(int x)
{
    string s = to_string(x);
    vector<int> cnt(10, 0);
    for(int i = 0; i < s.size(); i++)
    {
        int v = s[i] - '0';
        //cout<<v<<endl;
        cnt[v]++;
    }
    for(int i = 0; i <= 9; i++)
    {
        if(cnt[i] >= 2)return false;
    }
    return true;
}
void sol()
{
    int x;
    cin>>x;
    for(int i = x+1; i <= 9999; i ++)
    {
        if(isdistinct(i))
        {
            cout<<i;
            return;
        }

    }

}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    //I_O("test1", "test1");
    fast;
    if (multitest)
    {
        int t;
        cin >> t;
        while (t--)
        {
            sol();
        }
    }
    else
    {
        sol();
    }
    return 0;
}