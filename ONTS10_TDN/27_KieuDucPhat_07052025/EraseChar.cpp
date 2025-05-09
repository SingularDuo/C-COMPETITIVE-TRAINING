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
bool ispalin(string s)
{
    string sub = s;
    reverse(s.begin(), s.end());
    return sub == s;
}
void sol()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int remaining = n - k; 
    for(int i = 0; i <= n - remaining; i++) {
        string sub = s.substr(i, remaining);
        if(ispalin(sub)) {
            cout << sub << endl;
            return;
        }
    }
    
    cout << "No" << endl;
}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    I_O("EraseChar", "EraseChar");
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
