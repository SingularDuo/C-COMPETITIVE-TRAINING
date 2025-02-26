#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define king signed main()

vector<ll> current;
map<int, int> cnt;

void xucxac(ll dice, vector<ll>& a) {
    if (dice == 3) {
        ll sum = 0;
        for (auto i : current) {
            sum += i;
        }
        cnt[sum]++;
        return;
    }

    for (int i = 1; i <= a[dice]; i++) { 
        current.push_back(i);
        xucxac(dice + 1, a);
        current.pop_back();
    }
}

king {
    ll s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<ll> mat = {s1, s2, s3};
    
    xucxac(0, mat);

    ll max_freq = 0, best_value = LLONG_MAX;
    for (auto &p : cnt) {
        if (p.second > max_freq || (p.second == max_freq && p.first < best_value)) {
            max_freq = p.second;
            best_value = p.first;
        }
    }
    
    cout << best_value << endl;
}
