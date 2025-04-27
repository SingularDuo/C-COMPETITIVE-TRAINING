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
const int maxn =1e5;
void sol()
{
    fast;
    int n;
    cin >> n;
    vec(ll,a,n+1,0);
    vec(ll,cnt,maxn,0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }

    ll ans = 0;
    int ptr_right = 1;
    while (ptr_right <= n && cnt[a[ptr_right]] == 0) {
        cnt[a[ptr_right]]++;
        ptr_right++;
    }
    for (int i = 1; i <= n; i++) {
        ans += ptr_right - i; 
        cnt[a[i]]--; 
        while (ptr_right <= n && cnt[a[ptr_right]] == 0) {
            cnt[a[ptr_right]]++;
            ptr_right++;
        }
    }

    cout << ans << endl; 
}

KING_PHAT
{
    multitest = false;
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    I_O("NRSEQ", "NRSEQ");
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
