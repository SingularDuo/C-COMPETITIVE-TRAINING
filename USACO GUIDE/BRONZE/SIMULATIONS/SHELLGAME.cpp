#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
void init() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll maxpoint(ll start, const vector<pair<ll, ll>>& pos, const vector<ll>& guess) {
    ll maxpoint = 0;
    vector<ll> luu(3, 0);
    luu[start - 1] = 1;
    for (int i = 0; i <= pos.size() - 1; i++) {
        if (luu[pos[i].first - 1] == 1 || luu[pos[i].second - 1] == 1) { 
            if (luu[pos[i].first - 1] == 1) {
                luu[pos[i].first - 1] = 0;
                luu[pos[i].second - 1] = 1;
                start = pos[i].second;
            } else if (luu[pos[i].second - 1] == 1) {
                luu[pos[i].second - 1] = 0;
                luu[pos[i].first - 1] = 1;
                start = pos[i].first;
            }
        }
        if (luu[guess[i] - 1] == 1) maxpoint++; 
    }
    return maxpoint;
}

int main() {
    init();
    int n;
    cin >> n; 
    vector<pair<ll, ll>> pos;
    vector<ll> guess;
    for (int i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        pos.pb({a, b});
        guess.pb(c);
    }
    ll maxx = LLONG_MIN;
    for (ll i = 1; i <= 3; i++) {
        maxx = max(maxx, maxpoint(i, pos, guess));
    }
    cout << maxx << endl;
}
