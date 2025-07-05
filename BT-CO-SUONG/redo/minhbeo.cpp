#include <bits/stdc++.h>
using namespace std;
int n, k, res = 0;

void init(){
    freopen("giay.inp", "r", stdin);
    freopen("giay.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int power(int x){
    if (x == 1) return 2;

    if (x % 2 == 0) return power(x / 2) * power(x / 2);
    else return power(x / 2) * power(x / 2) * 2;
}

void solve(){
    cin >> k >> n;
    int len = power(k);

    for (int i = 1; i <= k ; i++){
        len /=2;
        if (n <= len){ n = len - n + 1; res++;}
        else n -= len;
    }

    cout << k - res + 1;
}

int main(){
    //init();
    solve();
    return 0;
}
