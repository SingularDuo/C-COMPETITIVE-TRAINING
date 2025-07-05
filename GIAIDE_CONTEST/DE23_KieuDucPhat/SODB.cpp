/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("SODB.inp", "r", stdin);
  freopen("SODB.out", "w", stdout);
  fast;
}
const int MAXN = 5 * 1e6;
bool isprime[MAXN + 5];

void sieve() {
    fill(isprime, isprime + MAXN + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * 1LL * i <= MAXN; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }
}
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * 1LL * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
bool isdb(int x)
{
    int cnt1 = 0, cnt2 = 0;
    while(x > 0)
    {
        if(x % 2 == 0)cnt1++;
        else cnt2++;
        x/=10;
    }
    return cnt1 != cnt2;
}
const int SUB1 = 5 * 1e6;
const int SUB2 =1e12;
__TOISETHIVOI__ {
    init();
    sieve();
    int n; cin>>n;
    int maxx = LLONG_MIN;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        maxx = max(a[i], maxx);
    }
    if(maxx <= 5 * 1e6)
    {
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] <= 0)continue;
            if(isprime[a[i]] && isdb(a[i]))res++;
        }
        cout<<res;
        return 0;
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= 0)continue;
        if(a[i] <= SUB1)
        {
            if(isprime[a[i]] && isdb(a[i]))
            {
                //cout<<a[i]<<endl;
                res++;
            }
        }
        else
        {
            if(isPrime(a[i]) && isdb(a[i]))
            {
                //cout<<a[i]<<endl;
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
