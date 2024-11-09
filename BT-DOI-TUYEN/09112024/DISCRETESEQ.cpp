#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> longlong(n);
    for (int i = 0; i < n; i++) cin >> longlong[i];
    for (auto& i : longlong) {
        cnt[i]++;
    }
    for (auto& a : cnt) {
        cout << a.first <<":"<< a.second << endl;
    }
}
