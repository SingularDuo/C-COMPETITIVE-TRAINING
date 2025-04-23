#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("NEARPAIR.INP", "r", stdin);
    freopen("NEARPAIR.OUT", "w", stdout);
    fast;
}
long long find(vector<long long>& a, long long x) {
    int n = a.size();
    int l = 0, r = n - 1;
    long long current = LLONG_MAX; 
    long long pos1 = -1, pos2 = -1;

    while (l < r) {
        long long sum = a[l] + a[r];
        if (abs(sum - x) < abs(current - x)) {
            current = sum;
            pos1 = a[l];
            pos2 = a[r];
        }
        if (sum < x) {
            l++;
        } else {
            r--;
        }

    }
    return abs(x - pos2 - pos1);
}

signed main() {
    //init();
    int m,n,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0;i < m; i++)cin>>b[i];

    return 0;
}