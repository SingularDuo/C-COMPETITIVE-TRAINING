#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("tongchuso.inp", "r", stdin);
    freopen("tongchuso.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    init();
    ll n, sum = 0;
    cin>>n;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    cout<<sum;
}
