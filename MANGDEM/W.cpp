/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'       
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    unordered_set<int> trung_binh;

    for (int k = 0; k < n; k++) {
        int ak = a[k];
        for (auto& i : freq) {
            int ai = i.fi;
            int aj = 2 * ak - ai;

            if (aj != ai && freq.count(aj)) {
                trung_binh.insert(ak);
                break;
            }
            if (aj == ai && i.se > 1) {
                trung_binh.insert(ak);
                break;
            }
        }
    }

    cout << trung_binh.size() << endl;
    return 0;
}
