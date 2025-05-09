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
    string a, s;
    cin >> a >> s;
    int value = 0;
    if((a == "A" && (s == "J" || s == "Q" || s == "K" || s == "10")) ||
       (s == "A" && (a == "J" || a == "Q" || a == "K" || a == "10")))
    {
        cout << "Blackjack" << endl;
        return;
    }
    if(isdigit(a[0]))
    {
        value = stoi(a);
    }
    else if(a == "J" || a == "Q" || a == "K")
    {
        value = 10;
    }
    else if(a == "A")
    {
        value = 11;
    }
    if(isdigit(s[0]))
    {
        value += stoi(s);
    }
    else if(s == "J" || s == "Q" || s == "K")
    {
        value += 10;
    }
    else if(s == "A")
    {
        if(value <= 10) value += 11;
        else value += 1;
    }
    if(a == "A" && s == "A")
    {
        value = 12;
    }
    int res = 0;
    for(int i = 0; i <= 11; i++)
    {
        if(i == 11)
        {
            if(value > 11)continue;
        }
        if(value + i <= 21)
        {
            res = max(res, value + i);
        }
        
    }
    cout<<res<<endl;
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
