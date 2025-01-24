//code trau - dpt O(n^2) ==> toi da n = 5x10^3 && q = 5 * 10^3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
    int n, q;
    cin>>n>>q;
    vector<int> a(n, 0);
    while(q--){
        ll s, e, k;
        cin>>s>>e>>k;
        for(int i = s-1; i < e; i++){
            a[i] = (a[i] + k);
        }
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}