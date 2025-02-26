#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool palin(ll n){
    string str1 = to_string(n);
    string str2 = to_string(n);
    reverse(str1.begin(), str1.end());
    return str1 == str2;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll i = k +1;
        while(!palin(i)){
            i++;
        }
        cout<<i<<endl;
    }
}