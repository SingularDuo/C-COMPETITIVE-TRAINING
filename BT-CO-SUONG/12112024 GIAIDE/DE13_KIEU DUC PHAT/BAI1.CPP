#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn = 1e6;
bool prime[maxn + 5];
void Sang() {
    for (int i = 2; i <= maxn; i++) prime[i] = 1;
    int m = sqrt(maxn);
    for (int i = 2; i <= m; i++)
        if (prime[i] == 1) {
            for (int j = i * i; j <= maxn; j += i) prime[j] = 0;
        }
}
bool latnguoc(int n) { 
    string s = to_string(n);
     bool is_alternating = true; 
     if (s.size() < 2) return false; 
     bool check02= s[0] < s[1]; 
     for (int i = 1; i < s.size() - 1; i++) { 
        int c = s[i] - '0'; int d = s[i + 1] - '0'; 
        if (check02 == true) { 
            if (c >= d) { 
                is_alternating = false; 
                break; } } 
        else { 
            if (c <= d) { 
                is_alternating = false; 
                break; 
                } 
        } 
        check02 = !check02; 
        } 
        return is_alternating; }
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
    vector<ll> filtered;
    for (int i = 0; i < n; i++) {
        if (dem(a[i]) == k) {
            filtered.push_back(a[i]);
        }
    }

    for (int i = 0; i < filtered.size(); i++) {
        if (prime[filtered[i]]) {
            if (latnguoc(filtered[i])) {
                cnt++;
                maxx = max(maxx, filtered[i]);
            }
        }
    }
    
    cout << cnt << endl;
    cout << maxx << endl;

    return 0;
}
