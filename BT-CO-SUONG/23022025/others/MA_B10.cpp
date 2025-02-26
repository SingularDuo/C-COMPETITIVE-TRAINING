#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define kING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("MA_B10.INP", "r", stdin);
    freopen("MA_B10.OUT", "w", stdout);
    fast;

}
ll cntz(ll n) {
    ll count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

ll find(ll k) {
    ll left = 1, right = 5 * k, answer = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (cntz(mid) >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

kING_PHAT
{
    //init();
    ll k;
    cin >> k;
    cout << find(k);
    return 0;
}
