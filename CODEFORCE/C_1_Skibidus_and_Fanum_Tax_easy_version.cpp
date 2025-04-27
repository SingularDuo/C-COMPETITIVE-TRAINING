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

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int n, m;
    cin >> n >> m; 
    vec(ll, a, n, 0);
    vec(ll, b, m, 0);

    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < m; i++) cin >> b[i]; 
    ll v = b[0];
    for(int i = 0; i < n;i ++)
    {
        if(i == 0)
        {
            a[i] = min(a[i], v - a[i]);
            continue;
        }
        ll c1 = min(a[i], v - a[i]);
        ll c2 = max(a[i], v - a[i]);
        if(c1 >= a[i-1])
        {
            a[i] = c1;
        }
        else
        {
            if(c2 < a[i-1])
            {
                cout<<"NO"<<endl;
                return;
            }
            else a[i] = c2;
        }
    }
    cout<<"YES"<<endl;
    return;
}

KING_PHAT {
    multitest = true;
    // Set input and output style if needed
    // I_O("test1", "test1");
    fast;
    if (multitest) {
        int t;
        cin >> t;
        while (t--) {
            sol();
        }
    } else {
        sol();
    }
    return 0;
}
