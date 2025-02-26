/*code de quy
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define king signed main()
vector<ll> current;
ll res = LLONG_MIN;
ll n, m;

void gen(ll idx, vector<ll>& a, ll sum)
{
    if(sum > m)return;
    if(current.size() == 3)
    {
        res = max(res, sum);
        return;
    }
    for(int i = idx; i < n; i++)
    {
        current.push_back(a[i]);
        gen(i + 1, a, sum + a[i]);
        current.pop_back();
    }
}
king {
    
    cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.rbegin(), a.rend());
    gen(0, a, 0);
    cout<<res;
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define king signed main()

king {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll res = LLONG_MIN;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll sum = a[i] + a[j];
            if (sum > m) break;
            int lo = j + 1, hi = n - 1, best = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (sum + a[mid] <= m) {
                    best = mid; 
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (best != -1) {
                res = max(res, sum + a[best]);
            }
        }
    }

    cout << res;
}
