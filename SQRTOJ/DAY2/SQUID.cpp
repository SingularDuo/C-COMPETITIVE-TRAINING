#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;
vector<ll> a;
vector<vector<ll>> ketqua;
vector<ll> current;

bool check(const vector<ll>& current) {
    if (current.size() <= 3) return true;
    vector<int> count(4, 0); // Array to count the occurrences of numbers from 1 to 4
    for (int i = 0; i < current.size(); i++) {
        if (current[i] < 1 || current[i] > 4) return false;  // Ensuring numbers are in the range [1, 4]
        count[current[i] - 1]++; 
    }
    for (int i = 0; i < 4; i++) {
        if (count[i] == 0 || count[i] > 1) return false; // Each number should appear exactly once
    }
    return true;
}

void gen(int idx, vector<ll>& current) {
    if (check(current)) {
        ketqua.push_back(current);
        return;
    }
    for (int i = idx; i < a.size(); i++) {
        current.push_back(a[i]);
        gen(i + 1, current);
        current.pop_back();
    }
}

KING_PHAT {
    fast;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    gen(0, current); 
    cout <<ketqua.size();
}
