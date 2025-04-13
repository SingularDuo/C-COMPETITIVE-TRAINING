#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mypow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;


	ll res = mypow(n, k/2);
	res = res * res;


	if(k % 2) res = res * n;
	return res;
}
ll log_b_of_a(ll b, ll a)
{
    return log2(a)/log2(b);
}
vector<ll> kdigit(62, 0);
void precompute(ll k, ll n)
{
    kdigit[0] = 1;
    for(int i = 1; i <= log_b_of_a(k, n); i++)
    {
        kdigit[i] = kdigit[i-1]*k;
    }
}
string toK(ll n, ll k)
{
    if(k >= 10)
    {
        vector<ll> v;
        while(n > 0)
        {
            ll a = n % k;
            v.push_back(a);
            n/=k;
        }
        string s = "";
        for(auto i : v)
        {
            if(i < 10)s = s+ to_string(i);
            else{
                s = s + char('A' + i - 10);
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string s = "";
    while(n > 0)
    {
        s = s + to_string(n%k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}
string toK_Nstring(string n, ll k)
{
    string result = "";
    while (!n.empty())
    {
        ll remainder = 0;
        string next_n = "";

        for (char digit : n)
        {
            remainder = remainder * 10 + (digit - '0');
            if (!next_n.empty() || remainder >= k)
            {
                next_n += (remainder / k) + '0';
            }
            remainder %= k;
        }
        if (remainder < 10)
            result += char('0' + remainder);
        else
            result += char('A' + remainder - 10);

        n = next_n;
    }
    reverse(result.begin(), result.end());
    return result;
}
ll getdigit(ll n, ll k, ll digit) {
    n /= kdigit[digit];
    return n % k;
}

ll setdigit(ll n, ll k, ll digit, ll newval)
{
    ll old_val = getdigit(n, k, digit);
    n -= old_val * mypow(k, digit);
    n += newval * mypow(k, digit);
    return n;
}

ll off_digit(ll n, ll k, ll digit)
{
    ll old_val = getdigit(n,k,digit);
    n -= old_val * mypow(k, digit);
    return n;
}
int main()
{
    ll n;
    ll k;
    ll digit,newval;
    cin>>n>>k>>digit;
    precompute(k,n);
    cout<<getdigit(n,k, digit);

}
/*

*/
/*
Thao tác chia từng chữ số:

Xử lý từng chữ số của chuỗi bằng cách giữ lại giá trị dư (remainder) sau mỗi phép chia.

Tạo một chuỗi mới (next_n) chứa phần số còn lại sau phép chia, để tiếp tục quá trình.

Xác định ký tự tương ứng:

Nếu giá trị dư nhỏ hơn 10, chuyển đổi nó thành chữ số ('0' đến '9').

Nếu giá trị dư từ 10 trở lên, chuyển đổi thành ký tự từ 'A' đến 'F' (hoặc cao hơn nếu cơ số lớn hơn 16).

Đảo ngược chuỗi:

Kết quả cuối cùng thu được phải đảo ngược để đúng thứ tự biểu diễn trong hệ số mới.

Kết quả cuối cùng:

Chuỗi kết quả được trả về dưới dạng biểu diễn của số n trong hệ số k.
*/
