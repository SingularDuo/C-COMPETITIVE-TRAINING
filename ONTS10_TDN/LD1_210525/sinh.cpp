#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "BERTRAN";
// Số test kiểm tra
const int NTEST = 1250;



// Viết lại hàm random để sử dụng cho thuận tiện.
// Hàm random này sinh ngẫu nhiên số trong phạm vi long long
// Số sinh ra nằm trong [L;R].
long long Rand(long long L, long long R) {
    assert(L <= R);
    return L + rand() % (R - L + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NA    ME + ".inp").c_str());
        int n = Rand(1, 10000000);
        inp<<n;
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}