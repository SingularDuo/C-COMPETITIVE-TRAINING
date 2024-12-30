#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("UCLNSL.INP","r",stdin);
    freopen("UCLNSL.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll modbig(const string& num, ll mod) {
    ll result = 0;
    for (char digit : num) {
        result = (result * 10 + (digit - '0')) % mod; 
    }
    return result;
}
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


string GCD(string a, string b) {
    if (a == "0") return b;
    if (b == "0") return a;
    ll smallB = modbig(a, 1e9 + 7); 
    ll remainder = modbig(b, smallB);
    return GCD(b, to_string(remainder));
}

int main() {
    init();
    string a, b;
    getline(cin, a);
    getline(cin, b);
    string result = GCD(a, b);
    cout << result << endl;

    return 0;
}
