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
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    //init();
    int k; cin>>k;
    string s; cin>>s;
    map<char,int> freq;
    for(int i =0;i < s.size(); i++)
    {
        freq[s[i]]++;
    }
    for(auto& i : freq)
    {
        if(i.second > 0 && i.second % k != 0)
        {
            cout<<-1;
            return 0;
        }
    }
    string current = "";
    for(auto& i : freq)
    {
        for(int j = 0; j < i.second/k; j++)current += i.first;
    }
    for(int i = 1; i <= k ; i++)cout<<current;

    return 0;
}
