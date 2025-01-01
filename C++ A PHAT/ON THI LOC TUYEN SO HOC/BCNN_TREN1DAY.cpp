#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
int main(){
    int n;
    cin>>n;
    // chay trau
    // uoc tinh chay dc n <= 10^5
    int a[n+1];
    for(int i = 1; i <= n; i++)cin>>a[i];
    int bcnn = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1)continue;
        int curr = lcm(a[i], a[i-1]);
        if(bcnn == 0){
            bcnn = curr;
            continue;
        }
        bcnn = lcm(bcnn, curr);
    }
    cout<<bcnn;
}