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
  freopen("KTD.inp", "r", stdin);
  freopen("KTD.out", "w", stdout);
  fast;
}
bool isPrime(int n) {
    if (n < 2) return true;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * 1LL * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void sol(){
    int n,l,r;
    cin>>n>>l>>r;
    int res=0;
    vector<int>a;
    for(int i=l;i<=r;i++){
        if(isPrime(__gcd(i,n))){
            res++;
            a.push_back(i);
        }
    }
    cout<<res<<endl;
    for(auto &i:a){
        cout<<i<<" ";
    }
}
__TOISETHIVOI__ {
   i nit();
    sol();
    return 0;
}
