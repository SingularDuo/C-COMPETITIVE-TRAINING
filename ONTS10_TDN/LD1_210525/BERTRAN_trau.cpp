#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
vector<bool> a(maxn + 5, false);
vector<int> primes;
int p;

void init(){
    freopen("bertran.inp", "r", stdin);
    freopen("bertran.ans", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    a[0] = a[1] = 1;
    for (int i = 2; i*i <= maxn; i++){
        if (!a[i]){
            for (int j = i * i; j <= maxn; j += i){
                a[j] = 1;
            }
        }
    }

    for (int i = 2; i <= maxn; i++){
        if (!a[i]) primes.push_back(i);
    }

    cin >> p;

    int cnt = 0;
    for (int i : primes){
        if (i > p && i < 2*p){
            cout << i << " ";
            cnt++;
        }
    }
    cout << '\n' << cnt;
}

int main(){
    init();
    solve();
    return 0;
}