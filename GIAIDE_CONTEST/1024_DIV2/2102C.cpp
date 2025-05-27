#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define TOISETHIVOI signed main()
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
    vector<vector<int>> a(n, vector<int>(n, 0));

    int top = 0, bot = n - 1;
    int l = 0, r = n - 1;
    int v = 0;

    while (top <= bot && l <= r)
    {
        for (int i = l; i <= r; i++)
        {
            a[top][i] = v++;
        }
        top++;

        for (int i = top; i <= bot; i++)
        {
            a[i][r] = v++;
        }
        r--;

        if (top <= bot)
        {
            for (int i = r; i >= l; i--)
            {
                a[bot][i] = v++;
            }
            bot--;
        }

        if (l <= r)
        {
            for (int i = bot; i >= top; i--)
            {
                a[i][l] = v++;
            }
            l++;
        }
    }

    int maxx = n * n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = maxx - a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

TOISETHIVOI
{
    // set state for multitest
    multitest = true;
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
