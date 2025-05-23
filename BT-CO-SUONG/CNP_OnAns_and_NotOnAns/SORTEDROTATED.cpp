#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void init()
{
    freopen("SORTEDROTATED.inp", "r", stdin);
    freopen("SORTEDROTATED.out", "w", stdout);
    fast;
}

KING_PHAT
{
    init();
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        int x;
        cin >> x;
        vector<ll> trai, phai;
        ll stop = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && a[i] < a[i - 1])
            {
                stop = i;
                break;
            }
            trai.push_back(a[i]);
        }

        for (int i = stop; i < n; i++)
        {
            phai.push_back(a[i]);
        }

        if (!trai.empty() && x <= trai.back() && x >= trai.front())
        {
            int l = 0, r = trai.size() - 1;

            while (l < r)
            {
                int mid = (l + r) / 2;
                if (trai[mid] >= x)
                    r = mid;
                else
                    l = mid + 1;
            }

            if (l < trai.size() && trai[l] == x)
            {
                cout << l << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            auto it = lower_bound(phai.begin(), phai.end(), x);

            if (it == phai.end() || *it != x)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << (it - phai.begin() + stop) << endl;
            }
        }
    }
}
