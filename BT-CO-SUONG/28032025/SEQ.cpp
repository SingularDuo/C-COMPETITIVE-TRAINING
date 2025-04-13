#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define cinint(a) scanf("%d", &a)
#define cinll(a) scanf("%lld", &a)
#define cinfloat(a) scanf("%f", &a)
#define cindouble(a) scanf("%lf", &a)
#define cinchar(a) scanf(" %c", &a)
#define cinstr(a) scanf("%s", a)

signed main(void)
{
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cinll(n);
    cinll(k);

    vector<int> a(n + 1, 0);
    vector<int> idx(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cinll(a[i]);
        a[i] += a[i - 1] - k;
        idx[i] = i;
    }

    vector<int> minn(n + 1, 0);
    minn[0] = LLONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        minn[i] = min(minn[i - 1], a[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll currj = -1;
        ll l = i, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (minn[mid] >= a[i])
            {
                currj = minn[mid];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        res = max(res, currj - i);
    }

    printf("%lld\n", res);
    return 0;
}
