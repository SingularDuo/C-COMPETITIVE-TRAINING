#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void genABC(ll n, string s) {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    for(auto i : {'A', 'B', 'C'}){
        if(s.empty() || s.back() != i) genABC(n, s + i);
    }
}
void sol(){
    ll n;
    cin>>n;
    genABC(n, "");
    return;
}
signed main() {
    sol();
    return 0;
}