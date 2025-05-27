#include <bits/stdc++.h>
using namespace std;

const string NAME = "09B";
const int NTEST = 1000;

string generateRandomString(int length) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;
    for (int i = 0; i < length; ++i) {
        result += chars[rand() % chars.size()];
    }
    return result;
}

long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rand() % (R - L + 1);
}

int main() {
    srand(time(NULL));
    
    for (int iTest = 1; iTest <= NTEST; iTest++) {

        int length = Rand(1, 1000);
        string s = generateRandomString(length);

        ofstream inp((NAME + ".inp").c_str());
        inp << s;
        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        // Compare output
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    
    return 0;
}
