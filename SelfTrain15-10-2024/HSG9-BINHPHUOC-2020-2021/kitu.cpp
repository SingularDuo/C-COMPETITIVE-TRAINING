#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("tienphoto.inp", "r", stdin);
    freopen("tienphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    string s;
    getline(cin, s);
    long long cnt = 0;
    for(int i = 1; i <= s.size(); i++){
        if(isdigit(s[i])){
            cnt++;
        }
    }
    cout<<cnt;
}
