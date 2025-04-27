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

void sol()
{
    int n;
    cin >> n;
    vec(ll, a, n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, maxx = 0, start = 0, end = 0;

    for (int r = 1; r < n; r++) {
        //cout<<"checking "<<a[r]<<" "<<a[r-1]<<" ans "<<a[r]*a[r-1]<<endl;
        if (a[r] * a[r - 1] >= 0) {
            l = r;
        }
        if (r - l + 1 > maxx) {
            maxx = r - l + 1;
            start = l;
            end = r;
            //cout<<a[start]<<" "<<a[end]<<endl;
        }
    }

    cout << start + 1 << " " << end + 1 << endl; 
}

KING_PHAT
{
    multitest = false;
    // multitest = true;
    I_O("SEGMENT", "SEGMENT");

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
