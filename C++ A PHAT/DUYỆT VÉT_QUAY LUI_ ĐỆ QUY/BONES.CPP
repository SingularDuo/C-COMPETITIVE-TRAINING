#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b) { 
    return a.second > b.second;
}
int main() {
    ll s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if(s1 <= 10 && s2 <= 10 && s3 <= 15){
        vector<pair<ll, ll>> f(s1 + s2 + s3 + 1);
        for(int i = 1; i <= s1+s2+s3; i++){
            f[i].first = i;
        } 
        for (ll i = 1; i <= s1; i++) {
            for (ll j = 1; j <= s2; j++) {
                for (ll k = 1; k <= s3; k++) {
                    f[i + j + k].second++; 
                }
            }
        }
        sort(f.begin(), f.end(), compare);
        cout << f[0].first; 
    }
    
    
}
