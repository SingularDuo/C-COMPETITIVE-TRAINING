#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("DP_B3.INP", "r",stdin);
    freopen("DP_B3.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    vector<pair<ll, ll>> giatri(n);
    for (int i = 0; i < n; i++) {
        ll va1, va2;
        cin >> va1 >> va2;
        a[i].first = va1;
        a[i].second = va2;
        giatri[i].first = va2 / va1;
        giatri[i].second = i;
    }
    sort(giatri.begin(), giatri.end(), greater<pair<ll, ll>>());
    vector<pair<ll, ll>> sorted(n);
    for (int i = 0; i < n; i++) {
        sorted[i].first = a[giatri[i].second].first;
        sorted[i].second = a[giatri[i].second].second;
    }
    ll i = 0;
    ll cnt = 0;
    while(sorted[i].first <= m ){
        m -= sorted[i].first;
        cnt+= sorted[i].second;
        i++;
    }
    cout<<cnt;

    return 0;
}
