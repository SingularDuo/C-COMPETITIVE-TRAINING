#include<bits/stdc++.h>
using namespace std;
#define int long long
void calculate_pair(const vector<int>& a, int n, int k, int& cnt) {
    map<int, int> hm;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k) cnt++;
        if (hm.find(sum - k) != hm.end()) cnt += hm[sum - k];
        hm[sum]++;
    }
}

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    calculate_pair(a, n, k, cnt);
    cout <<cnt;
}
signed main(){
    sol();
}
