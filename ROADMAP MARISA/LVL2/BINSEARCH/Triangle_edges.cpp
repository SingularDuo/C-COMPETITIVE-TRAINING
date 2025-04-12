#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    // tong hai canh lon hon canh con lai
    /*
    ai + aj > ak
    => ak < ai + aj
    ai + ak > aj
    => ak > aj - ai
    ak + aj > ai
    => ak > ai - aj

    => min_k = max(ai - aj, aj - ai)
    => max_k = ai + aj - 1
    */
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int min_k = max(a[i] - a[j], a[j] - a[i]);
            int max_k = a[i] + a[j] - 1; 

            auto it = lower_bound(a.begin() + j + 1, a.end(), min_k);
            auto it2 = upper_bound(a.begin() + j + 1, a.end(), max_k); 

            if (it != a.end() && it2 != a.end()) res += distance(it, it2); 
            else if (it != a.end() && it2 == a.end())
            {
                res += distance(it, a.end()); 
                // khog co phan tu nao bang thi => tat ca thang dang sau deu co the di vs cap i, j
            }
            else
                continue;
        }
    }
    cout << res << endl; 
}
