#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("CAUDO.inp", "r", stdin);
    freopen("CAUDO.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    string s = "";
    long long n;
    cin >> n;
    while (n > 0) {
        if (n % 2 == 0) s = "O " + s;
        else s = "A " + s;
        n /= 2; 
    }
    while (s.size() < 9) { 
        s = "O " + s;
    }
    cout<<s<<endl;
    return 0;
}
