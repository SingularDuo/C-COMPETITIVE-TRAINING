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
    string s, s1;
    getline(cin, s);
    getline(cin, s1);
    ll res = 0;
    for (int l = 0; l < s1.size(); l++) 
    {
        if (s1[l] != s[0]) continue;
        int r = l;
        int idx_in_s = 0;
        bool done = false;
        while (r < s1.size() && !done) 
        {
            if(s1[r] == '-')break;
            if (s1[r] == s[idx_in_s])
            {
                s1[r] = '-'; 
                if (idx_in_s == s.size() - 1)
                {
                    done = true;
                    break;
                }
                idx_in_s++;
            }
            r++;
        }
        if (done) res++;
    }
    cout << res;
}

KING_PHAT
{
    multitest = false;
    I_O("SUBREP", "SUBREP");
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
