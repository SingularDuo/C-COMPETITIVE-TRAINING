#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, k;
    cin>>n>>k;
    vector<int> vec(n);
    for(ll i = 1; i < n; i++) cin>>vec[i];
    for(ll i = 1; i < n; i++){
        for(int j = i+1; j < i+k; j++){
            if(vec[j] == vec[i]){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<-1;

}
