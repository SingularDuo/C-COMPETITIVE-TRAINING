#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAt signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

string find(int n) {
    string result = "";
    n++;

    while (n > 1) {
        if (n % 2 == 0) result = '4' + result;
        else result = '7' + result;
        n /= 2;
    }
    return result;
}

KInG_PHAt
{
    fast;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << find(n) << endl;
    }
}
