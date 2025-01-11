#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    init();
    int n, q;
    cin>>n>>q;
    int a[n+1];
    int psum1[n+1];
    int psum2[n+1];
    int psum3[n+1];
    psum1[0] = 0;
    psum2[0] = 0;
    psum3[0] = 0;
    for (int i = 1; i <= n; i++) {
        int breed;
        cin >> breed;
        psum1[i] = psum1[i - 1] + (breed == 1);
        psum2[i] = psum2[i - 1] + (breed == 2);
        psum3[i] = psum3[i - 1] + (breed == 3);
    }
    
    for(int i = 1; i <= n; i++){

    }
    while(q--){
        int l, r;
        cin>>l>>r;
        ll f1 =0, f2 = 0, f3 =0;
        f1 = psum1[r] - psum1[l-1];
        f2 = psum2[r] - psum2[l-1];
        f3 = psum3[r] - psum3[l-1];
        cout<<f1<<" "<<f2<<" "<<f3<<endl;

    }
}