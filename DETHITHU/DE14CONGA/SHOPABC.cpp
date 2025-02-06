#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll calculate(ll l, ll r) {
    return ((r - l + 1) / 2) + 1;
}

void sol() {
    ll n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    ll maxx = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll cnta = 0, cntb = 0, cntc = 0;
            for(int k = i; k <= j; k++){
                if(s[k] == 'a')cnta++;
                else if(s[k] == 'b')cntb++;
                else cntc++;
            }
            ll curr = calculate(i, j);
            if(cnta > curr || cntb > curr || cntc > curr)maxx = max(maxx, (ll) (j - i + 1));
            

        }
    }
    cout<<maxx;
}

signed main() {
    sol();
    return 0;
}
