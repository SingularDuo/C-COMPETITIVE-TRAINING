# Tiếp tục với phương pháp giải bài Quy Hoạch Đông - DP
---
## I. HƯỚNG SUY NGHĨ
---
#### Cũng giống như lối suy nghĩ đệ quy, bài toán DP sẽ có nhiều bước suy nghĩ tương tự
- Các bước bao gồm:
    - *Bước 1:* Tìm mối liên hệ và thể hiện ý nghĩa của mảng dp (có thể là *dp[i] hoặc dp[i][j]*) 
        - Ở bước này, sau nhiều bài làm, tôi nhận thấy rằng ý nghĩa của mảng quy hoạch động thường đi chung với yêu cầu đề bài.

        - **Ví dụ bài NKPALIN:** Ta có thể thấy đề bài yêu cầu in ra xâu con palindrome dài nhất và không còn liên tiếp ==> Lúc này ta có thể định nghĩa mảng dp[i][j] là xâu palindrome dài nhất trong đoạn từ i đến j
    - *Bước 2:* Xác định các bài toán con, trường hợp biên dùng để giải bài toán lớn
        -  **Ví dụ:* Với bài toán tính sô fibonacci, ta có thể thấy chúng ta cần xác định 