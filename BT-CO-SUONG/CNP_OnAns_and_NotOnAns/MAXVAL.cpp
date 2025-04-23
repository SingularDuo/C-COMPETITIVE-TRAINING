#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int maxn = 1e6;
bool isprime[maxn + 1];

void init()
{
    freopen("MAXVAL.INP", "r", stdin);
    freopen("MAXVAL.OUT", "w", stdout);
    fast;
}
void sieve() {
    fill(isprime, isprime + maxn + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

KING_PHAT {
    init();
    fast;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = LLONG_MIN;
    for (int i = n - 1; i > 0; i--) {  
        int left = 0, right = i - 1; 
        while (left <= right) {
            int mid = (left + right) / 2;

            res = max(res, a[i] % a[mid]); 

            if (a[mid] < a[i] / 2) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    cout << res << endl;
}
