#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string find(string& a, string& b)
{
    for(char i = 'z'; i >= 'a'; i--)
    {
        ll pos1 = a.find(i), pos2 = b.find(i);
        if(pos1 != string::npos && pos2 != string::npos){
            a = a.substr(pos1+1);
            b = b.substr(pos2+1);
            string res = find(a, b);
            return i + res;
        }
    }
    return "";
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    string res = find(s1, s2);
    cout<<res;

}
/*
** Học thêm được gì? **
* Khái niệm về thứ tự từ điển
* Hiểu thêm về khi sử dụng dấu & để tham chiếu và không sử dụng
* cách chạy code theo dạng " Tối ưu từng phần "
* Dạng bài cần tìm từ kí tự lớn nhất ==> lớn t2 => lớn t3 =>...=> lớn cuối cùng
* Hàm find() luôn trả về vị trí đầu tiên
* Hiểu rõ hơn về cách sử dụng đệ quy
* Lỗi memory limit khi sử dụng đệ quy & cách khắc phục hiệu quả


Tại sao ban đầu có ý tưởng nhưng sai?
- Chỉ lấy 1 kí tự
- Đọc thiếu đề ( " KHÔNG CẦN LIÊN TIẾP ")
- Dạng bài sử dụng đệ quy nhưng chưa nắm bắt rõ
*/
