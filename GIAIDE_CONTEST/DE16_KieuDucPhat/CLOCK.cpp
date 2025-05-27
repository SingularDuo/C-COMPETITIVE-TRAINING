#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long


signed main()
{
    freopen("CLOCK.inp", "r", stdin);
    freopen("CLOCK.out", "w", stdout);
    
    int m, n; 
    cin >> m >> n;

    int result = (m + n) % 60;
    cout << result;
    return 0;
}
