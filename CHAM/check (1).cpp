#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 100000;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện.
// Hàm random này sinh ngẫu nhiên số trong phạm vi long long
// Số sinh ra nằm trong [L;R].
long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rd() % (R - L + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        // ofstream inp((NAME + ".inp").c_str());
        // // Code phần sinh test ở đây
        // inp.close();

        system("sinhtest.exe");
        system("main.exe");
        system("trau.exe");
        // Nếu dùng linux thì thay fc bằng diff
        if (system("fc output.txt ans.txt") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
