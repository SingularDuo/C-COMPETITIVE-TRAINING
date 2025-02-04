#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool can(ll x){
    string s = to_string(x);
    string s1 = s.substr(0, 2); 
    string s2 = s.substr(2, 2); 
    ll dau = stoi(s1); 
    ll cuoi = stoi(s2); 
    if(dau > 18 || cuoi > 18) return false;
    else return true;
}

ll tim_so(ll x){
    ll res = 0;
    for(ll i = 1; i <= 9; i++){
        for(ll j = i; j <= 9; j++){
            if(i + j == x){
                res = i*10 + j; 
                return res;
            }
        }
    }
    return 0;
}

void sol(){
    ll x;
    cin >> x;
    if(!can(x)){ 
        cout << "0";
        return;
    }
    string s = to_string(x);
    string s1 = s.substr(0, 2); 
    string s2 = s.substr(2, 2); 
    ll dau = stoi(s1); 
    ll cuoi = stoi(s2);
    string res = "";
    ll tran1 = tim_so(dau);
    ll tran2 = tim_so(cuoi);
    res = to_string(tran2) + to_string(tran1); 
    cout << res;
    return;
}
signed main() {
    init();
    sol();
    return 0;
}
