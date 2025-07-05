#include <bits/stdc++.h>
using namespace std;

// Custom comparator for sorting numbers correctly
bool cmp(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size(); // Shorter numbers come first

    // If sizes are equal, compare **digit by digit** as actual numbers
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }

    return false; // Strings are identical
}

signed main() {   
    string s;
    cin >> s;
    vector<string> numbers;

    for (size_t i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            string curr = "";
            while (i < s.size() && isdigit(s[i])) { 
                curr += s[i];
                i++;
            }
            numbers.push_back(curr);
        }
    }

    sort(numbers.begin(), numbers.end(), cmp);

    for (const auto &num : numbers) cout << num << " ";
    
    return 0;
}
