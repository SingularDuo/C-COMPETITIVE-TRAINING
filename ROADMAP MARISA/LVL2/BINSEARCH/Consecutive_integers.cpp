#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, start, maximum;
vector<ll> a;
vector<int> getUniqueElements(const vector<int>& inputVector) {
    set<int> uniqueSet(inputVector.begin(), inputVector.end());
    return vector<int>(uniqueSet.begin(), uniqueSet.end());
}
vector<ll> genans(int start, int range) {
    vector<ll> ans;
    for (int i = start; i < start + range; i++) {
        ans.push_back(i);
    }
    return ans;
}
KING_PHAT {
    fast;
    cin >> n;
    int subn = n;
    a.resize(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    a = getUniqueElements(a);
    sort(a.begin(), a.end());

    ll res = LLONG_MAX;

    for (int i = 0; i < a.size(); i++) {
        ll currmax = a[i] + subn-1;
        ll appear = 0;
        for(int j = i; j < a.size();j++)
        {
            if(a[j] > currmax)break;
            //cerr<<a[j]<<" "<<currmax<<endl;
            appear++;
        }
        res  = min(res, subn - appear);
    }

    cout << res;
}
