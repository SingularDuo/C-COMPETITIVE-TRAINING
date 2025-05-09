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
    string s;
    getline(cin, s);
    int n = s.size();
    string format = "";
    for(int i = 0; i < n; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            format += s[i];
        }
        if((s[i-1] >= 'a' && s[i-1] <= 'z') || (s[i-1] >= 'A' && s[i-1] <= 'Z'))
        {
            if(s[i] == ' ' )
            {
                format += ' ';
            }
        }
    }
    for(int i = 0; i < format.size(); i++)
    {
        format[i] = tolower(format[i]);
    }
    format[0] = toupper(format[0]);

    for(int i = 0; i < format.size(); i++)
    {
        if(format[i] == ' ')
        {
            format[i+1] = toupper(format[i+1]);
        }
    }
    cout<<format<<endl;
}
KING_PHAT
{
    multitest = true;
    fast;
    if (multitest)
    {
        int t;
        cin >> t;
        cin.ignore(); 
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
