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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<int> cnt(1e5 + 1, 0); 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    int ptr_right = 1;
    while (ptr_right <= n && cnt[a[ptr_right]] == 0) {
        cnt[a[ptr_right]]++;
        ptr_right++;
    }
    for (int i = 1; i <= n; i++) {
        ans += ptr_right - i;
        cnt[a[i]]--;
        while (ptr_right <= n && cnt[a[ptr_right]] == 0) {
            cnt[a[ptr_right]]++;
            ptr_right++;
        }
    }

    cout << ans << endl;
}