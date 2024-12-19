#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[3];
ll b[3][3][3] = {0};
vector<ll> f(80);
ll dequy(ll x, ll y, ll z, ll b1, ll b2, ll b3){
    bool check = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(b[i][j][k] == 0) check = false;
            }
        }
    }
    
    if(check == true){  
        return 1; 
    }
    b[x][y][z] = 1;
    f[x+y+z]++;
    if(b[x+1][y][z] == 0 && x+1 <= b1) dequy(x+1,y,z,b1,b2,b3);  
    if(b[x][y+1][z] == 0 && y+1 <= b2) dequy(x,y+1,z,b1,b2,b3);  
    if(b[x][y][z+1] == 0 && z+1 <= b3) dequy(x,y,z+1,b1,b2,b3); 
}
int main(){
    ll f_size = 0;
    for(int i = 0; i <= 2; i++){
        cin>>a[i];
    }
    ll result = dequy(a[0],a[1],a[2],a[0],a[1],a[2]); 
    sort(f.begin(),f.end(),greater<ll>());
    cout<<f[0];
}
