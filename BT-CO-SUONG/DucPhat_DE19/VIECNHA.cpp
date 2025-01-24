#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e9+1;
void init(){
    freopen("VIECNHA.INP", "r", stdin);
    freopen("VIECNHA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    long long n, k;
    cin >> n >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, cnt = 0;
    while (i < k && n >= a[i]) {
        n -= a[i];
        i++;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}
