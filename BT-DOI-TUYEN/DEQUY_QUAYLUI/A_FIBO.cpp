#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KInG_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
KInG_PHAT
{
    fast;
    int n;
    cin>>n;
    cout<<fibonacci(n);
}