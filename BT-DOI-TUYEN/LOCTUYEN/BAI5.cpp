#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll nen(ll n) {
    ll cnt = 0;
    ll i = 2; 
    while (n > 2) {
        if (n % i != 0) {
            n = i; 
            i = 2; 
            cnt++;
        } else {
            i++;
        }
    }
    return cnt;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll cnt = 0;
    for (ll i = 2; i <= 42; i++) {
        ll first = i;

        ll mul_b = b / first;         
        ll last_b = first * mul_b;  

        ll mul_a = a  / first; 
        ll last_a = first * mul_a;   

        ll amt = ((last_b - first) / i) + 1;
        ll amt_a = ((last_a - first) / i) + 1;
        cout<<"first"<<i<<endl;
        cout<<"lastb"<<last_b<<endl;
        cout<<"lasta"<<last_a<<endl;
        cout<<endl;
        ll rng = amt - amt_a;
        cnt += rng * (nen(i) + 1);
    }

    cout << cnt << endl;
    return 0;
}

/*
các số nén lần đầu tiên sẽ về trong khoảng từ 2 --42
* vì nếu như một số P nén lần đầu về x ==> P là bội chung của các số từ 1 đến x - 1

Vậy chỉ cần tìm trong đoạn A ---> B  có bao nhiêu số chia hết cho 1,2,3,...,42
* Dùng ý tưởng của Psum ==> từ 1 --> B - (1-->A-1)
Áp dụng công thức tìm tổng số lần nén như sau:
gọi k là số lượng số có lần nén đầu tiên vê y
=> tổng số lần nén sẽ bằng K *(nen(y) + 1)    [cộng 1 vì mỗi số mất thêm 1 lần để về y]
cộng lại ra res cuối cùng
Bài toán hiện tại cần giải là số lượng số từ 1 đến B có lần nén đầu tiên về 2 --> 42
*/