#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int, int>> f(k);
    for(int i = 0; i < k; i++)cin>>f[i].first>>f[i].second;
    vector<vector<int>> a(n, vector<int>(n)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int curr_i1 = i, curr_j1 = j;
            while(curr_i1 > 0 && curr_j1 > 0){
                curr_i1 -= 3;
                curr_j1 -= 3;
            }
            if(i == 0 || j == 0 || i == n-1 || j == n-1 || curr_i1 == 0 && curr_j1 == 0){ 
                a[i][j] = 1; // 1 = red;
                continue;
            } 
            int curr_i2 = i, curr_j2 = j;
            while(curr_i2 > 1 && curr_j2 > 1){ 
                curr_i2 -= 3;
                curr_j2 -= 3;
            }
            if(i == 1 || j == 1 || i == n - 2 || j == n - 2 || curr_i2 == 1 && curr_j2 == 1){ 
                a[i][j] = 2; //2 = blue
                continue;
            }
            int curr_i3 = i, curr_j3 = j;
            while(curr_i3 > 2 && curr_j3 > 2){
                curr_i3 -= 3;
                curr_j3 -= 3;
            }
            if(i == 2 || j == 2 || i == n - 3 || j == n - 3 || curr_i3 == 2 && curr_j3 == 2){ 
                a[i][j] = 3; //3 = yellow
                continue;
            }

        }
    }
    for(int i = 0; i < k;i++){
        int first = f[i].first - 1 , s = f[i].second - 1; 
        if(a[first][s] == 1){
            cout<<"RED" << endl; 
            continue;
        }
        if(a[first][s] == 2){
            cout<<"BLUE" << endl; 
            continue;
        }
        if(a[first][s] == 3){
            cout<<"YELLOW" << endl; 
            continue;
        }
    }
}
