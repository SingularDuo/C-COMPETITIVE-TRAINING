#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
void init() {
    freopen("QBSEQ.inp", "r", stdin);
    freopen("QBSEQ.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> prefix(n+5); 
    prefix[0] = a[0]; 
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    int soluong = 0;
    for(int i = 1; i <= n; i++){
        for(int j  = i+1; j <= n; j++){
            int current = prefix[j] - prefix[i-1];
            if(current % k  == 0){
                int currsoluong = j - i + 1;
                soluong = max(currsoluong,soluong);
            }
        }
    }
    cout<<soluong;

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