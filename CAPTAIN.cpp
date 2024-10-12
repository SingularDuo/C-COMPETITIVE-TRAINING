#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
bool prime[maxn + 5];
int a, b;
bool isprime(long long n){
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(long long i=5; i*i<=n; i++){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
bool cright(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        string x  = s.substr(0, i+1);
        int t = stoi(x);
        if (!isprime(t)) {
            return false;
        }
    }
    return true; 
}
bool cleft(int n){
    string s = to_string(n);
    int len = s.length();
    for(int i = 0; i < len;i++){
        string x = s.substr(i, len - i);
        int t = stoi(x);
        if(!isprime(t)){
            return false;
        }
    }
    return true; 
}

void sol() {
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; 
        bool left = cleft(a);
        bool right = cright(a);
        if (left && right) {
            cout << "CENTRAL" << endl;
        } else if (left && !right) {
            cout << "LEFT" << endl;
        } else if (!left && right) {
            cout << "RIGHT" << endl;
        } else {
            cout << "FINED" << endl;
        }
    }
}
int main(){
    sol();
    return 0;
}
