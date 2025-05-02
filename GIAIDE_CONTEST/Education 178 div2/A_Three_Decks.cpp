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
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    int s = a+b+c;
    if(s % 3 != 0 || a > s/3 || b > s/3)
    {
        cout<<"NO"<<endl;
        return;
    }
    int aneed = s/3 - a;
    int bneed = s/3 - b;
    if(c - aneed - bneed == s/3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
KING_PHAT
{
    multitest = true;
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