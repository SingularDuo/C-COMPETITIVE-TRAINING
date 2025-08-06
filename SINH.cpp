#include <bits/stdc++.h>
using namespace std;

const string NAME = "J97";
const int NTEST = 10000;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int main() {
    for (int test = 1; test <= NTEST; ++test) {
        ofstream inp((NAME + ".inp").c_str());

        int n = Rand(2, 100);  // nhỏ lại để chạy kiểm tra nhanh
        int m = Rand(0, 1000);
        int k = Rand(1, n);

        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 1);
        shuffle(nodes.begin(), nodes.end(), rd);

        vector<int> gov(nodes.begin(), nodes.begin() + k);
        sort(gov.begin(), gov.end());

        inp << n << " " << m << " " << k << "\n";
        for (int i = 0; i < k; ++i)
            inp << gov[i] << " \n"[i == k - 1];

        set<pair<int, int>> edges;

        auto is_gov = [&](int x) {
            return binary_search(gov.begin(), gov.end(), x);
        };

        int tries = 0;
        while ((int)edges.size() < m && tries < m * 10) {
            int u = Rand(1, n), v = Rand(1, n);
            if (u == v) continue;
            if (is_gov(u) && is_gov(v)) continue;
            if (u > v) swap(u, v);
            if (edges.count(make_pair(u, v))) continue;
            edges.insert(make_pair(u, v));
            ++tries;
        }

        // ❌ Không dùng structure binding
        for (set<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); ++it) {
            int u = it->first;
            int v = it->second;
            inp << u << " " << v << "\n";
        }

        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (system(("fc " + NAME + ".out " + NAME + ".ans > nul").c_str()) != 0) {
        cout << "Test " << test << ": ❌ WRONG!\n";
        system(("fc " + NAME + ".out " + NAME + ".ans").c_str());
        cout << "Saving test input...\n";
        system(("copy " + NAME + ".inp wrong_" + to_string(test) + ".inp").c_str());
        return 0;
    }

    }
    return 0;
}
