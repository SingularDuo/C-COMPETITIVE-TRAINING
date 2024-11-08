#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int countOccurrences(const string& s, const string& sub) {
    int count = 0;
    size_t pos = s.find(sub);

    while (pos != string::npos) {
        count++;
        pos = s.find(sub, pos + 1);
    }
    return count;
}
int main() {
    string s;
    getline(cin, s);
    string sub = "virus";
    int result = countOccurrences(s, sub);
    cout << result << endl;

    return 0;
}
