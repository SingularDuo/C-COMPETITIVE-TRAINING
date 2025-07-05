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

void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}

void phantich(int n, vector<pair<ll, ll>>& a)
{
    int cnt2 = 0;
    while(n % 2 == 0)
    {
        n/=2;
        cnt2++;
    }
    if(cnt2 != 0)a.push_back({2, cnt2});
    for(int i = 3; i * i <= n; i++)
    {
        if(isprime[i] && n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            a.push_back({i, cnt});
        }
    }
    if(n != 1)
    {
        a.push_back({n, 1});
    }
}
int dissss(vector<pair<ll, ll>>& fa, vector<pair<ll, ll>>& fb)
{
    map<ll, ll> freq;
    for (auto& i : fa) freq[i.first] += i.second;
    for (auto& i : fb) freq[i.first] -= i.second;

    int dist = 0;
    for (auto& i : freq) dist += abs(i.second);

    return dist;
}

__TOISETHIVOI__ {
    //init();
    sieve();

    int n; cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        vector<pair<ll, ll>> fa, fb;
        phantich(a, fa);
        phantich(b, fb);

        cout << dissss(fa, fb) << endl;
    }

    return 0;
}

