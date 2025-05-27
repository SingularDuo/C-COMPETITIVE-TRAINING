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
 * Generated on: 2025-05-16 09:17:00
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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

//const int MOD = 1e9 + 7;
//const int INF = 2 * 1e18;

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
/**
 goi y: ta se bat cap theo chieu tu nho den lon nhu vay thi khi i nho thi ta buoc phai rap voi i + k
 12345678910
1 - 5 => 5 - 1
2 - 6 => 6 - 2
3 - 7 => 7 - 3
4 - 8 => 8 - 4

 k = 4
 */
 /*
 1 2 3 4 5 6 7 8
 3 4 1 2 7 8 5 6
  */
__TOISETHIVOI__ {
    //init();
 
    int n, k; cin>>n>>k;
    
    if(n % 2 != 0)
    {
        cout<<"-1";
        return 0;
    }
    vector<ll> res(n + 1, 0);
    for(int i = 1; i <= n ; i++)
    {
        //cout<<res[i]<<" "<<res[i+k]<<endl;
        if( i + k <= n && res[i] == 0 && res [i + k] == 0 )
        {
          res[i] = i + k;
          res[i + k] = i;
          //cout<<res[i]<<" "<<res[i+k]<<endl<<endl;
        }
        else if(i - k > 0 && res[i] != 0 && res[i-k] != 0) continue;
        else{
          cout<<-1;
          return 0;
        }
    }
    for(int i = 1; i <= n; i++)cout<<res[i]<<" ";
    
    return 0;
}