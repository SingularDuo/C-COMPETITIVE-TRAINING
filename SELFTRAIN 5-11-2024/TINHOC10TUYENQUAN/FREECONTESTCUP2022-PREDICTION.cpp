#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int tim(ll u, ll k) {
    vector<int> a; 
    for (int i = 1; i <= sqrt(u); i++) {
        if(u % i  == 0)
        {
            a.push_back(i);
            if(u /i != i) a.push_back(u/i);
        }
    }
    sort(a.begin(), a.end());
    if(k <= a.size()){
        return a[k - 1];
    }
    else return -1;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    for (ll i = 0; i < n; i++) {
        cout << tim(vec[i].first, vec[i].second) << endl;
    }
    return 0;
}
