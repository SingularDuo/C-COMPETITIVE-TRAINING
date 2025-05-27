// Problem: 03D. An Giang - Bài 4 - Chữ số cuối cùng (2 điểm)
// Contest: Codeforces - Đề tuyển sinh toàn quốc năm học 2024-2025 phần 1
// URL: https://codeforces.com/gym/604749/problem/03D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long

int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

signed main() {
    int a, b;
    cin >> a >> b;
    
    int last = a % 10;
    
    if (last == 1 || last == 0 || last == 5 || last == 6) {
        cout << last;
        return 0;
    }
    
    vector<int> cycle;
    set<int> seen;
    
    int cur = last;
    while (seen.find(cur) == seen.end()) {
        seen.insert(cur);
        cycle.push_back(cur);
        cur = (cur * last) % 10;
    }
    
    int ss = cycle.size();
    int idx = (b - 1) % ss;
    
    cout << cycle[idx];
    
    return 0;
}
