#include <bits/stdc++.h>

using namespace std;
const int NTEST = 1000;
const int MOD = 1e9;
mt19937_64 rng(time(0));
int R(int l, int r)
{
    return l + rng() % (r - l + 1);
}
int main()
{
    for (int ITEST = 1; ITEST <= NTEST; ITEST++)
    {
        int n = R(1, 100), q = R(1, 100);
        ofstream out("test.inp");
        out << n << " " << q << endl;
        for (int i = 0; i < n; i++)
        {
            out << R(1, 100) << " ";
        }
        out << endl;
        for (int i = 0; i < n; i++)
        {
            int t = R(1, 2);
            out << t << " ";
            if (t == 1)
            {
                int i = R(1, n);
                int x = R(1, 100);
                out << i << " " << x << endl;
            }
            else
            {
                int l = R(1, n);
                int r = R(l, n);
                out << l << " " << r << endl;
            }
        }
        out.close();
        system("./code");
        system("./trau");

        if (system("diff test.ans test.out"))
        {
            cout << "Test #" << ITEST << "die" << endl;
            break;
        }
        else
        {
            cout << "Test #" << ITEST << "song" << endl;
        }
    }
}