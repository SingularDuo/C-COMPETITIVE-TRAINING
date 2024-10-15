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
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long sum = 0;
    if(a % 2 == 0){
        sum +=a;
    }
    if(b % 2 == 0){
        sum +=b;
    }
    if(c % 2 == 0){
        sum +=c;
    }
    if(d % 2 == 0){
        sum +=d;
    }
    cout<<sum;


    return 0;
}
