//not optimized
#include<bits/stdc++.h>
using namespace std;
int check(int n, int p, int q, int r){
    int cntt = 0;
    for(int i = 1; i<= n;i++){
        int cnt = 0;
        if(i % q == 0)cnt++;
        if(i % r == 0)cnt++;
        if(i % p == 0)cnt++;
        if(cnt == 2) cntt++;
    }
    return cntt;
}
int main() {
    long long n, p, q, r;
    while (cin >> n >> p >> q >> r) {
        cout << check(n, p, q, r) << endl;
    }
    return 0;
}
