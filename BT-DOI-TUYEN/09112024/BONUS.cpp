#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll maxtong = a[0] + n;  
    int i = 0;
    ll original_n = n; 
    while (n > 0 && i < original_n) {  
        a[i] = a[i] + n;
        n--;
        i++;
    }
    ll cnt = 0;
    for (ll j = 0; j < original_n; j++) {
        if (a[j] == maxtong) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}