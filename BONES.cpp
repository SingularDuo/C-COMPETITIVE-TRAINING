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
    if( a >= 0 &&  a % 2 == 0)
    {

    }
    if( a >= 0 || a % 2 == 0)
    
    cout << best_value << endl;
}
