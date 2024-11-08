# Bài tập tuyển 02-11-2024

## Mục lục 
- [DPAIRS](#dpairs)
- [MaxDist](#maxdist)
- [ProductToSum](#producttosum)
- [Chair - Chuỗi vòng](#chair---chuỗi-vòng)

## DPAIRS
### Đề bài
- Cho mảng $A$ và số nguyên $k$.
- Tìm số cặp $(i, j)$ khác nhau sao cho $A[i] - A[j] = k$ .
### Code
Các thao tác hay sử dụng với map:
```cpp=
map<int, int> mp;

mp[3] = 1;  // gan gia tri
mp[3]++;   // mp[3] = mp[3] + 1;

cout << mp[3] << endl;  // lay gia tri ben phai cua 3

for (auto pair : mp) {
    cout << pair.first << " " << pair.second << endl;
}
```

## MaxDist
### Đề bài
Cho dãy số nguyên $A$. 
Tìm khoảng cách lớn nhất giữa $2$ phần tử bằng nhau trong dãy.

## ProductToSum
### Đề bài
- Chia dãy A thành 2 dãy con bên trái và bên phải.
- Gọi $S1$ là tổng các phần tử trong dãy bên trái, $S2$ là tổng các phần tử trong dãy bên phải.
- Kết quả bài toán là $S1 \times S2$.

## Ctime
### Đề bài
- Có $N$ người làm việc trong một công ty. Mỗi người làm từ khung giờ $a_i$ đến khung giờ $b_i$.
- Cần trả lời $2$ câu hỏi: 
    1. Khoảng thời gian dài nhất không có người làm việc.
    2. Khoảng thời gian dài nhất mà có ít nhất $1$ người làm việc.
- $1 \leq N \leq 5000$.
- $1 \leq a_i, b_i \leq 10^6$.

## QuanTrong
### Đề bài
- Cho mảng $A$ gồm $N$ số nguyên.
- Một đoạn $[l, r]$ được gọi là đặc biệt nếu $A[l] = A[r]$.
- Tìm đoạn đặc biệt có tổng lớn nhất.

### Code
Tìm vị trí đầu tiên mà giá trị val xuất hiện trong mảng a
```cpp=
// first[val] = k; thì val xuất hiện lần đầu tiên ở vị trí k 
// nếu val không xuất hiện trong mảng a thì first[val] = -1
int first[1005] = {-1}; 

for(int i = 0; i < n; i++) {
    if (first[a[i]] == -1) {
        first[a[i]] = i;
    }
}
```

Tìm vị trí cuối cùng mà giá trị val xuất hiện trong mảng a
```cpp=
// last[val] = k; thì val xuất hiện lần cuối cùng ở vị trí k
// nếu val không xuất hiện trong mảng a thì last[val] = -1
int last[1005] = {-1};

for(int i = n - 1; i >= 0; i--) {
    last[a[i]] = i;
}
```

## Chair - Chuỗi vòng
