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
    long long l,m,n,sum = 0;
    cin>>l>>m>>n;
    if(l == 3){
        if(m == 1){
            if(n >= 100){
                sum += 500 * n;
            }
            else {
                sum += 600 * n;
            }

        }
        if(m == 2){
            if(n >= 100){
                sum += 700 * n;
            }
            else {
                sum += 800 * n;
            }
        }
    }
    if(l == 4){
        if(m == 1){
            if(n >= 100){
                sum += 250 * n;
            }
            else {
                sum += 300 * n;
            }

        }
        if(m == 2){
            if(n >= 100){
                sum += 350 * n;
            }
            else {
                sum += 400 * n;
            }
        }
    }
    cout<<sum;


    return 0;
}
