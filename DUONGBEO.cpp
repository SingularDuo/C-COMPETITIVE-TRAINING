// this is for all 9A11 girls
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // this is how boys love you guy can be presented
        double x, y, size = 10;
    string message(" CHUC MUNG 8/3 ");
    int print_line = 4;
    if (message.length() % 2 != 0) message += " ";
    for (x = 0; x < size; x++)
    {
        for (y = 0; y <= 4 * size; y++)
        {
            double dist1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
            double dist2 = sqrt(pow(x - size, 2) + pow(y - 3 * size, 2));

            if (dist1 < size + 0.5 || dist2 < size + 0.5) {
                cout << "V";
            }
            else cout << " ";
        }
        cout << "\n";
    }
    for (x = 1; x < 2 * size; x++)
    {
        for (y = 0; y < x; y++) cout << " ";

        for (y = 0; y < 4 * size + 1 - 2 * x; y++)
        {
            if (x == print_line) {
                int idx = y - (4 * size - 2 * x - message.length()) / 2;
                if (idx < message.length() && idx >= 0) {
                    cout << message[idx];
                }
                else cout << "V";
            }
            else cout << "V";
        }
        cout << endl;
    }

    cout << "             FROM 9A11 BOYS\n";

    return 0;
}
