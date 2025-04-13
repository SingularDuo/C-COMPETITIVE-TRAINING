#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int maxn = 1e6;
vector<ll> a(maxn+5);

void init(){
    freopen("LISMAXSUMPRIME.inp","r",stdin);
    freopen("LISMAXSUMPRIME.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool prime[maxn + 1];
void sieve() {
    for (int i = 0; i <= maxn; i++) prime[i] = true;
    prime[1] = prime[0] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool checkvalid(int l, int r, vector<ll>& a)
{
    for(int i = l+1; i <= r; i++)
    {
        if(a[i] <= a[i-1])
        {
            return false;
        }
    }
    return true;
}

void solve() {
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int maxcounts = 1;
        for(int i = 1; i <= n; i++) {
            int counts = 1;
            for(int j = i+1; j <= n; j++) {
                if(a[j] > a[j-1]) {
                    counts++;
                } else {
                    break;
                }
            }
            maxcounts = max(maxcounts, counts);
        }

        int maxx = -1;
        for(int i = 1; i <= n - maxcounts + 1; i++) {
            int j = i + maxcounts - 1;
            if(checkvalid(i, j, a)) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    if(prime[a[k]])sum+=a[k];
                }
                maxx = max(maxx, sum);
            }
        }

        cout << maxcounts << " " << maxx << "\n";
    }
}

signed main(){
    init();
    solve();
}
/*
3
9
4 2 3 5 1 6 7 8 9
10
2 3 5 7 4 1 6 5 4 8
5
2 2 2 2 2
*/
