#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("Hai_mu_n.inp","r",stdin);
    freopen("Hai_mu_n.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
string nhan2 (string n)
{
    string res ="";
    int du = 0;
    for (int i = n.size() -1 ; i>=0; i--) {
        int curr = (n[i] - 48) *2 + du;
        du = curr/10;
        res.push_back(curr%10 + 48);
    }
    if (du) {
        while (du != 0) {
            res.push_back(du%10 + 48);
            du/=10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
string ress(int n)
{
    string res = "1";
    for (int i = 1; i<=n; i++) {
        res = nhan2(res);
    }
    return res;
}
int main()
{
    init();
    int n;
    cin>>n;
    cout<<ress(n);
    return 0;
}