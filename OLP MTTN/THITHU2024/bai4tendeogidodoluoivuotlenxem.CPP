#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    fast;
    int n;
    cin >> n;
    int res = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        set<int> s;
        int min_val = a[i], max_val = a[i]; 
        for(int j = i; j < n; j++)
        {
            s.insert(a[j]);
            min_val = min(min_val, a[j]);
            max_val = max(max_val, a[j]);

            if (s.size() == max_val - min_val + 1)res++;
        }
    }
    cout << res << '\n';
}
