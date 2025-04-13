#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool isprime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    for (int i = 5; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

signed main() {
    string s;
    cin >> s;

    int day = 0, month = 0, year = 0;
    int idx = 0;

    while (idx < s.size() && s[idx] != '/') {
        day = day * 10 + (s[idx] - '0');
        idx++;
    }
    idx++;
    while (idx < s.size() && s[idx] != '/') {
        month = month * 10 + (s[idx] - '0');
        idx++;
    }
    idx++;
    while (idx < s.size()) {
        year = year * 10 + (s[idx] - '0');
        idx++;
    }

    if (month == 13) {
        if (day == 1) {
            cout << "29/11/" << year << endl;
            cout << "02/13/" << year << endl;
            return 0;
        }
        if (day == 2) {
            cout << "29/11/" << year << endl;
            cout << "03/13/" << year << endl;
            return 0;
        }
        if (day == 3) {
            cout << "02/13/" << year << endl;
            cout << "05/13/" << year << endl;
            return 0;
        }
        if (day == 4) {
            cout << "03/13/" << year << endl;
            cout << "05/13/" << year << endl;
            return 0;
        }
        if (day == 5) {
            cout << "03/13/" << year << endl;
            cout << "02/02/";
            int suby = year + 1;
            cout << setw(4) << setfill('0') << suby << endl;
            return 0;
        }
    }

    if (month == 1) {
        cout << "05/13/";
        int suby = year - 1;
        cout << setw(4) << setfill('0') << suby << endl;
        cout << "02/02/";
        suby+=1;
        cout << setw(4) << setfill('0') << suby << endl;
        return 0;
    }

    auto ngay = [](int month) -> int {
        if (month >= 1 && month <= 12) return 30;
        if (month == 13) return 5;
        return 0;
    };

    int currday = day - 1, currmonth = month, curryear = year;

    while (true) {
        if (currday == 0) {
            currmonth--;
            if (currmonth == 0) {
                currmonth = 13;
                curryear--;
            }
            currday = ngay(currmonth);
        }
        if (isprime(currday) && isprime(currmonth)) {
            cout << setw(2) << setfill('0') << currday << "/";
            cout << setw(2) << setfill('0') << currmonth << "/";
            cout << setw(4) << setfill('0') << curryear << endl;
            break;
        }
        currday--;
    }

    currday = day + 1, currmonth = month, curryear = year;

    while (true) {
        if (currday > ngay(currmonth)) {
            currday = 1;
            currmonth++;
            if (currmonth > 13) {
                currmonth = 1;
                curryear++;
            }
        }
        if (isprime(currday) && isprime(currmonth)) {
            cout << setw(2) << setfill('0') << currday << "/";
            cout << setw(2) << setfill('0') << currmonth << "/";
            cout << setw(4) << setfill('0') << curryear << endl;
            break;
        }
        currday++;
    }

    return 0;
}
