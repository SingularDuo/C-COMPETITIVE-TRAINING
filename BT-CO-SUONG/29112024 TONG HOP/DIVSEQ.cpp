#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void init() {
    freopen("DIVSEQ.inp", "r", stdin);
    freopen("DIVSEQ.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int n, k;
    cin >> k >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
        cnt[prefix[i] % k]++;
    }
    int soluong = 0;
    for (auto i : cnt) {
        if (i.second > 1) {
            soluong += (i.second * (i.second - 1)) / 2; 
        }
    }
    cout << soluong;

    return 0;
}

/*
logic theo bài SUMSEQ0, sẽ có mối liên hệ giữa các phần tử %k   == 0
*/
/*
cần tìm mối liên hệ giữa các đoạn, prefix sum %k == 0
*/
/*
6 5
11 6 7 12 20 8
*/
/*
10 3
2 3 5 7 9 6 12 7 11 15
*/
