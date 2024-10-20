#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> buoc(k);
    for(int i = 0; i < n;i++) cin>>a[i];
    for(int i = 0; i < k; i++)cin>>buoc[i];
    vector<int>cong(n, 0);
    a[0] = 1;
    cong[0] = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == 0) continue;
        for(int j = 0; j < k; j++){
            if (i - buoc[j] >= 0 && a[i - buoc[j]] == 1) {
                cong[i] += cong[i - buoc[j]];
            }
        }
    }
    cout<<cong[n-1];
    
    return 0;
}
