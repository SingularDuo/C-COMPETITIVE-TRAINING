#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ra,rb;
        if(n % 2 == 0)
        {
            cout<<n/2<<" "<<n/2<<endl;
            continue;
        }
        ll val = n/2;
        for(int i = val; i <= n; i++)
        {
            if(i % (n-i) == 0)
            {
                cout<<n-i<<" "<<i<<endl;
                break;
            }
        }
    }
}
