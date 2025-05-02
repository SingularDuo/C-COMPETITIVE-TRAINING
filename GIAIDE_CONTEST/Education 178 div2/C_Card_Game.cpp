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
string case1 = "Alice";
string case2 = "Bob";
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n == 2)
    {
        if(s == "AB")cout<<case1<<endl;
        else cout<<case2<<endl;
        return;
    }
    vector<ll> a,b;
    bool alice = false,bob =false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A')
        {
            a.push_back(i); 
        }
        else
        {
            b.push_back(i);
        }
    }
    if(a.size()==1)
    {
        cout<<case2<<endl;
        return;
    }
    else if(a.size() >= n-1)
    {
        cout<<case1<<endl;
        return;
    }
    else{
        if(s[n-1] == 'A' && (s[n-2] == 'A' || s[0] == 'A'))cout<<case1<<endl;
        else cout<<case2<<endl;
    }

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