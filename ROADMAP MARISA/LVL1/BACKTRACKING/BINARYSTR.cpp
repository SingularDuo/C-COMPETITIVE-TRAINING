#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void gen(ll n, string s){
    if(s.size() ==  n){
        cout << s << endl;
        return;
    }
    gen(n, s + "0");
    gen(n, s + "1");
}
void sol(){
    ll n;
    cin>>n;
    gen(n, "");
    return;
}
signed main() {
    sol();
    return 0;
}