#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n; 
        double berries_needed = ceil(n * 4 / 3);
        cout << berries_needed << endl;
    }
}
