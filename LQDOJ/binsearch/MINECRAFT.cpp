#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define cinint(a) scanf("%d", &a)
#define cinll(a) scanf("%lld", &a)
#define cinfloat(a) scanf("%f", &a)
#define cindouble(a) scanf("%lf", &a)
#define cinchar(a) scanf(" %c", &a)
#define cinstr(a) scanf("%s", a)

int main()
{
    ll n, w;
    cin>>n>>w;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll last_min = -1;
    while (w > 0)
    {
        ll pos = -1;
        ll curr_min = -1;
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] > last_min)
            {
                right = mid - 1;
            }
            else
            {
                curr_min = a[mid];
                pos = mid;
                right = mid - 1;
            }
        }
        if (pos != -1)
        {
            a[pos]++;
            last_min = curr_min;
            w--;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    cout << a[0] << endl;
    return 0;
}
