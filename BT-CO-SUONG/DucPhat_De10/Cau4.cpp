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
 * Generated on: 2025-05-16 18:47:08
*/

#include <bits/stdc++.h>
using namespace std;

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

      freopen("Cau4.inp", "r", stdin);
      freopen("Cau4.out", "w", stdout);
      fast;
}
bool safe(string s)
{
    if(s.size() < 6)return false;
    bool ap1 = false, ap2 = false, ap3 = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')ap1 = true;
        if(s[i] >= 'A' && s[i] <= 'Z')ap2 = true;
        if(s[i] >= '0' && s[i] <= '9')ap3 = true;
    }
    return ap1 && ap2 && ap3;
}
__TOISETHIVOI__ {
       init();
    string s;
    cin >> s;
    
    ll res = 0;
    int n = s.size();
    
    int j = 0, upper = 0, lower = 0, app = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && (!upper || !lower || !app || j - i < 6)) {
            upper |= isupper(s[j]);
            lower |= islower(s[j]);
            app |= isdigit(s[j]);
            j++;
        }
        if (upper && lower && app && j - i >= 6) {
            res += (n - j + 1);
        }
        upper -= isupper(s[i]);
        lower -= islower(s[i]);
        app -= isdigit(s[i]);
    }
    
    cout << res << endl;
    return 0;
}