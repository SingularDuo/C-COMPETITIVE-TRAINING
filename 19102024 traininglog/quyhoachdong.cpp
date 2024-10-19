#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define ll long long
int a[maxn];
int cong[maxn];
void sol(){
    int n;
    cin>>n;
    for(int i = 1; i <= n;i++){
        cin>>a[i];
    }
    cong[0] = 1;
    a[0] = 1;
    for(int i = 1 ; i <=n;i++){
        if(a[i] == 0){
            cong[i] = 0;
            continue;
        }
        cong[i] = cong[i-1]* a[i-1];
        if(i - 2 >= 0){
            cong[i] += cong[i-2]*a[i-2];
        }
        if(i - 3 >= 0){
            cong[i] += cong[i-3]*a[i-3];
        } 

    }
    cout<<cong[n];
}

int main() {
    sol();

}
