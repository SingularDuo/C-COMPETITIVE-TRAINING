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
void sol()
{
    int n, x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector<char> a(s.size());
    for(int i = 0; i < s.size(); i++)
    {
        a[i] = s[i];
    }
    //for(auto& i : a)cout<<i<<" ";
    while(x > 0)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(a[i] == 'B' && a[i + 1] == 'G')
            {
                swap(a[i], a[i+1]);
                i++;
            }
        }
        x--;
    }
    for(auto& i : a)cout<<i;

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