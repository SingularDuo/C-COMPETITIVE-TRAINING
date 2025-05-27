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
 * Generated on: 2025-05-14 16:01:42
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
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

const int maxn = 500;

__TOISETHIVOI__ {
    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0;
    int pos = -1;  
    int m[7] = {9, 7, 3, 9, 7, 3, 9};

    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            pos = i;
            continue;
        }
        ///cout<<(s[i] - '0') <<endl;
        sum += (s[i] - '0') * m[i];
    }
    if(sum % 10 == 0)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '?')
            {
                cout<<0;
                continue;
            }
            cout<<s[i];
        }
        return 0;
    }
    if(s.size() == 6)
    {
        int mul = m[pos];
        for(int i = 0; i <= 9; i++)
        {
            if(((mul * i) + sum)%10 == 0)
            {
                for(int j = 0; j < s.size(); j++)
                {
                    if(s[j] == '?')
                    {
                        cout<<i;
                        continue;
                    }
                    cout<<s[j];
                }
                return 0;
            }
        }
    }
    int mul = m[pos];
    for(int i = 0; i <= 9; i++)
    {
        
        if(((mul * i) + sum)%10 == 0)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(s[j] == '?')
                {
                    cout<<i;
                    continue;
                }
                cout<<s[j];
            }
            return 0;
        }
    }


    return 0;
}


 