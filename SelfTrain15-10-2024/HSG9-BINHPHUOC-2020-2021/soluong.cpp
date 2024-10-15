#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("soluong.inp", "r", stdin);
    freopen("soluong.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0; i <n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int dem = 0;
    for(int i = 0; i < n; i++ ){
        if(vec[i] != vec[i+1]){
            dem++;
        }
    }
    cout<<dem;


    return 0;
}
