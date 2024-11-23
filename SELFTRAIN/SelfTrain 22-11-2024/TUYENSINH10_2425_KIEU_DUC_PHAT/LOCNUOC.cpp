#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("LOCNUOC.inp", "r", stdin);
    freopen("LOCNUOC.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    ll n, m;
    cin >> n >> m;

    vector<ll> hethong(n); 
    vector<ll> tank(m);   
    for (int i = 0; i < n; i++) cin >> hethong[i]; 
    for (int i = 0; i < m; i++) cin >> tank[i];   
    vector<ll> loc(m); 
    for (int j = 0; j < m; j++) { 
        for (int i = 0; i < n; i++) { 
            if (hethong[i] >= tank[j]) { 
                loc[j] += tank[j];      
                hethong[i] -= tank[j];  
            }
            else{
                loc[j] += hethong[i];
                hethong[i] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) { 
        if (loc[i] != 0) cout << loc[i] << " "; 
    }
}
