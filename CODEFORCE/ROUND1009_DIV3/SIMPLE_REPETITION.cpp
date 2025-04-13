#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        ll x, k;
        cin>>x>>k;
        if(k == 1)
        {
            if(isPrime(x))
            {
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
        else{
            if(x == 1 && k == 2)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }


}
