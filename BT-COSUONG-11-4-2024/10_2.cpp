#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("10_2.inp", "r", stdin);
    freopen("10_2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n;
    cin >> n;
    vector<int> vec;
    while (n > 0) {
        int a = n % 2;
        vec.push_back(a);
        n /= 2;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i];
    }
    cout << endl;  
    return 0;
}
