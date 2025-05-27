#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Tên chương trình
const string NAME = "GIFT";
// Số test kiểm tra
const int NTEST = 100;

typedef long long ll;

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
        ofstream inp((NAME + ".inp").c_str());
        int n = Rand(1, 1000);
        inp << n << " ";
        int k = Rand(1, 100);
        inp << k << " ";
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            a[i] = Rand(1, 10000);
            inp << a[i] << " ";
        }
        inp.close();

        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        // Nếu dùng Linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
