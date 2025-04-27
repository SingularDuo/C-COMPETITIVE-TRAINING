#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((input_name ".inp"), "r", stdin); freopen((output_name ".out"), "w", stdout); fast;

bool multitest = false;

void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol()
{
    int n, m, k;
    cin >> n >> m >> k;

    vec(ll, a, n, 0);
    vec(ll, b, m, 0);
    vec(ll, query, k, 0);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> query[i];

    sort(all(a));
    sort(all(b));

    for (int s : query)
    {
        ll min_diff = LLONG_MAX;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < m && a[i] + b[j] < s) j++;
            if (j < m) min_diff = min(min_diff, abs(a[i] + b[j] - s));
            if (j > 0) min_diff = min(min_diff, abs(a[i] + b[j - 1] - s));
        }

        cout << min_diff << endl;
    }
}

KING_PHAT
{
    // Set state for multitest
    // multitest = true;

    // Set state for I/O style
    I_O("SEQGAME", "SEQGAME");

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
