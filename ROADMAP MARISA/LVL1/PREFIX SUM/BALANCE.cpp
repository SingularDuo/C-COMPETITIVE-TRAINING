#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int countSubstrings(string s) {
    int n = s.length();
    int count = 0;
    unordered_map<int, int> map;
    int sum = 0;

    map[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            sum--;
        } else {
            sum++;
        }

        if (map.find(sum) != map.end()) {
            count += map[sum];
        }

        map[sum]++;
    }

    return count;
}
void sol(){
    string s;
    getline(cin, s);
    cout<<countSubstrings(s);

}
signed main() {
    sol();
    return 0;
}
/*for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            sum--;
        } else {
            sum++;
        }

        if (map.find(sum) != map.end()) {
            count += map[sum];
        }

        map[sum]++;
    }
*/