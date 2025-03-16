#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int n, k;
vector<ll> current;

void print(vector<ll>& a) {
    for (auto i : a) cout << i << " ";
    cout << endl;
}

void gen(int idx) {
    if (current.size() == k) {
        print(current);
        return;
    }
    for (int i = idx + 1; i <= n; i++) {
        current.push_back(i);
        gen(i);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    gen(0);
    return 0;
}
