#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6;
bool prime[maxn + 5];

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
    bool is_alternating = true; 
    if (s.size() < 2) return false; 
    bool check02 = s[0] < s[1]; 
    for (int i = 1; i < s.size() - 1; i++) { 
        int c = s[i] - '0'; 
        int d = s[i + 1] - '0'; 
        if (check02) { 
            if (c >= d) { 
                is_alternating = false; 
                break; 
            } 
        } else { 
            if (c <= d) { 
                is_alternating = false; 
                break; 
            } 
        } 
        check02 = !check02; 
    } 
    return is_alternating; 
}

int dem(int n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
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
        if (prime[a[i]] && latnguoc(a[i])) {
            cnt++;
        }
    }
    
    ll need = 0;
    for (int i = x; i >= 0; i--) {
        if (prime[i] && latnguoc(i)) {
            need = i;
            break;
        }
    }
    
    cout << cnt << endl;
    cout << need << endl;

    return 0;
}
