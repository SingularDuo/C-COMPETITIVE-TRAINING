#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define TOISETHIVOI signed main()

TOISETHIVOI
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    int max_second = 0;  

    for (int i = 0; i < n; i++)
    {
        if (a[i].second < max_second)
        {
            cout << "Happy Alex";
            return 0;
        }
        max_second = max(max_second, a[i].second);
    }
    cout << "Poor Alex";
}
