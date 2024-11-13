#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("BAI2.inp", "r", stdin);
    freopen("BAI2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool check(int n) {
    return n == 1 || n == 2 || n == 3 || n == 5 || n == 7;
}

int main() {
    init();
    string s;
    int cnt = 0;   
    getline(cin, s);
    ll maxx = 0;  
    string current = "";
    string largest = "";

    for(int i = 0; i < s.size(); i++) {
        ll n = s[i] - '0';
        if(check(n)) {
            cnt++; 
            current += s[i]; 
        } else {
            if(current.size() > largest.size() || (current.size() == largest.size() && current > largest)) {
                largest = current;
            }
            current = "";  
        }
    }
    if(current.size() > largest.size() || (current.size() == largest.size() && current > largest)) {
        largest = current;
    }

    cout << cnt << endl;
    cout << largest<< endl;
    return 0;
}
