#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
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
