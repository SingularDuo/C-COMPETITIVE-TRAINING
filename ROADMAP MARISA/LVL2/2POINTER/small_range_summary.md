# Những điều đã hiểu về bài Small range
## 1. Lí do sử dụng multiset
-   Multiset cũng giống như set nhưng cho lưu trữ những giá trị giống nhau, hoạt động giống như set ==> auto sort phần tử bé nhất về đầu và lớn nhất về cuối

## 2. Vòng lặp for
-   *for (int r = 0; r < n; r++)* Đang chạy các biến $R$ cho các đoạn, với mỗi đoạn từ $L$ --> $R$ ($L$ bắt đầu từ 0)
- Với mỗi $R$, chúng ta sẽ push vô trong multiset kia, và sẽ dùng *while()* để tăng $L$ lên đến khi nào chênh lệch là <=$k$
- Tại sao công thức $R-L+1$ lại được dùng để tính số dãy con? ( em cg không biết =)) ) nhưng mà nó hoạt động đươc
- **EM MS HIỂU ĐƯỢC ĐẾN ĐÂY THÔI, CÓ GÌ A GIẢNG KỸ LẠI DÙM E=)))**