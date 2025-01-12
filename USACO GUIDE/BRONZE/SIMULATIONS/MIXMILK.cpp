#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void init(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    vector<pair<ll, ll>> bucket(3);
    for (int i = 0; i < 3; i++) {  
        ll con, val;
        cin >> con >> val;
        bucket[i] = {con, val};
    }
    int last = 0;  
    for (int i = 1; i <= 100; i++) {
        int next = (last + 1) % 3; 
        ll trans = min(bucket[last].second, bucket[next].first - bucket[next].second);
        bucket[last].second -= trans;
        bucket[next].second += trans;
        last = next;
    }
    for (int i = 0; i < 3; i++) {
        cout << bucket[i].second << endl;
    }
    return 0;
}
