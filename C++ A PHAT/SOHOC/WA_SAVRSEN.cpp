#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MAXN = 1e7;
vector<int> sumDiv(MAXN, 0);
void tonguoc() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i + i; j < MAXN; j += i) {  
            sumDiv[j] += i;
        }
    }
}
ll calf(ll n)
{
    return n - sumDiv[n];
}
KING_PHAT
{
    fast;
    tonguoc();
    int a, b;
    cin>>a>>b;
    ll res = 0;
    for(int i = a; i <= b; i++)
    {
        res += abs(calf(i));
    }
    cout<<res;



}