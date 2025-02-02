#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void gensub(ll n, ll len, string s ){
    if (s.size() == len) {
        map<int, int> cnt;
        for(char c : s){
            if(c == '0'){
                cnt[0]+=2;
            }
        }
        for(char c: s){
            cnt[c- '0']++;
        }
        for(auto& it: cnt){
            if(it.second > 1)return;
        }
        for (char c : s) cout << c << " ";
        cout << "\n";
        return;
    }
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        for(auto c : s){
            char check = char(i);
            if(c == check){
                a[check - '0']++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            gensub(n, len, s + char(i + '0'));
        }
    }
}
void sol(){
    ll n, k;
    cin>>n>>k;
    gensub(n, k, "");
    return;
}
signed main() {
    sol();
    return 0;
}
