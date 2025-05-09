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

const int MOD = 1e9 + 7;

void sol()
{
    string s;
    cin >> s;

    int ans = 1;        
    int n = s.length(); 

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    int i = 0;
    while (i < n) {
        char current_char = s[i]; 
        int j = i; 
        while (j < n && s[j] == current_char) {
            j++;
        }
        int block_length = j - i; 
        ans = (ans * block_length) % MOD;
        i = j;
    }
    cout << ans << endl;
}

KING_PHAT 
{
    fast;

    bool multitest = false; 
    // multitest = true; 

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