#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6;
bool prime[maxn + 5];
void init() {
    freopen("BAI1.inp", "r", stdin);
    freopen("BAI1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void Sang() {
    for (int i = 2; i <= maxn; i++) prime[i] = 1;
    int m = sqrt(maxn);
    for (int i = 2; i <= m; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= maxn; j += i) prime[j] = 0;
        }
    }
}

bool latnguoc(int n) { 
    string s = to_string(n); 
    if (s.length() < 2) return false;
    bool increasing = s[0] < s[1]; 
    for (int i = 0; i < s.length() - 1; ++i) { 
        if ((increasing && s[i] >= s[i + 1]) || (!increasing && s[i] <= s[i + 1])) { 
            return false; 
            } 
            increasing = !increasing; 
        } 
    return true;
}

int main() {
    init();
    Sang();
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    ll maxx = 0;
    int k;
    cin >> k;
    ll x = pow(10, k);
    for (int i = 0; i < n; i++) {
        if (prime[a[i]]) {
            if(latnguoc(a[i])){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    ll need = 0;
    for (int i = x; i >= 0; i--) {
        if (prime[i] && latnguoc(i)) {
            cout<<i;
            return 0;
        }
    }
    
    
    cout << need << endl;

    return 0;
    
}
/*
   
*/