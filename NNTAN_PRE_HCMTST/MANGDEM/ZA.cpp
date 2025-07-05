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
 * Generated on: 2025-07-04 08:54:01
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

  fast;
}
int brute(string s)
{
    int res = -INF;
    for(int i =0 ; i < s.size(); i++)
    {
        int cntA = 0, cntB = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(s[j] == 'A')cntA++;
            else cntB++;
            if(abs(cntA - cntB) <= 1)
            {
                res = max(res, j - i + 1);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    return res;
}
int solve(string &s) {
    int n = s.size();
    map<int, int> first_pos;
    int diff = 0, res = 0;

    first_pos[0] = -1; 

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') diff++;
        else diff--;

        if (first_pos.count(diff)) {
            res = max(res, i - first_pos[diff]);
        } 
        else {
            first_pos[diff] = i;
        }

        if (first_pos.count(diff - 1))
            res = max(res, i - first_pos[diff - 1]);
        if (first_pos.count(diff + 1))
            res = max(res, i - first_pos[diff + 1]);
    }

    return res;
}

const int BRUTE = 1e3;
__TOISETHIVOI__ {
    init();
    string s; 
    while(getline(cin, s))
    {
        if(s.size() <= BRUTE)
        {
            int res = brute(s);
            cout<<res<<endl;
            continue;
        }
        int ans = solve(s);
        cout<<ans<<endl;
        
    }
    return 0;
}