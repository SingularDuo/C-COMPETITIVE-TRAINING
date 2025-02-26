#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("NUMBERS.INP","r",stdin);
    freopen("NUMBERS.OUT","w",stdout);
    faster;
}
int main() {
    init();
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll le = 0, chan = 0;
    vector<int> chancnt(n, 0), lecnt(n, 0);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) chan++;
        else le++;

        if (i == 0) {
            chancnt[i] = (a[i] % 2 == 0);
            lecnt[i] = (a[i] % 2 != 0);
        } else {
            chancnt[i] = chancnt[i - 1] + (a[i] % 2 == 0);
            lecnt[i] = lecnt[i - 1] + (a[i] % 2 != 0);
        }
    }

    if (chan == 0 || le == 0) {
        cout << "-1";
        return 0;
    }
    if (chan % 2 != 0 && le % 2 != 0) {
        cout << "-1";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        ll chan_truoc = (i > 0) ? chancnt[i - 1] : 0;
        ll chan_sau = chancnt[n-1] - chancnt[i];
        ll le_truoc = (i > 0) ? lecnt[i - 1] : 0;
        ll le_sau = lecnt[n-1] - lecnt[i];

        if (chan_truoc == chan_sau || le_truoc == le_sau) {
            cout << i; 
            return 0;
        }
    }
    cout << "-1";
}

/*
7
1 2 4 5 8 3 12
*/