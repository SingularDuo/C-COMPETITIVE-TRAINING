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
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    string head = "Heads", tail = "Tails";
    ll cnt1 = 0, cnt2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] == head)
        {
            ll streak = 0;
            while(i < n && a[i] == head)
            {
                streak++;
                i++;
            }
            cnt1 = max(cnt1, streak);
            i--; 
        }
        else if(a[i] == tail)
        {
            ll streak = 0;
            while(i < n && a[i] == tail)
            {
                streak++;
                i++;
            }
            cnt2 = max(cnt2, streak);
            i--; 
        }
    }
    
    cout << cnt1 << " " << cnt2 << endl;
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
