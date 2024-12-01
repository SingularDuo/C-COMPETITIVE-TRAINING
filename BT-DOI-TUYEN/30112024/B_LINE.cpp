#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int m, n, k;
map<int, int> ball;

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            ball[x]++;
        }
    }

    vector<int> cnt;
    for (auto &p : ball) {
        cnt.push_back(p.second);
    }

    sort(cnt.rbegin(), cnt.rend());

    int result = 0;
    for (int i = 0; i < min(k, (int)cnt.size()); i++) {
        result += cnt[i];
    }

    cout << result << endl;
    return 0;
}