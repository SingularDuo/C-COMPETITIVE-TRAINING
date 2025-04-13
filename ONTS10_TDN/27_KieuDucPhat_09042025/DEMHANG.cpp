#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    freopen("DEMHANG.inp", "r", stdin);
    freopen("DEMHANG.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<pair<ll, ll>> faek(cnt.begin(), cnt.end());
    sort(faek.begin(), faek.end(), cmp);

    for (const auto &p : faek)
    {
        cout << p.first << " " << p.second << endl;
        return 0;
    }

    return 0;
}



/*
11
1
2
2
3
2
4
5
2
6
7
6
*/
