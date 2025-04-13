#include <iostream>
#include <vector>
using namespace std;

// Hàm quay lui để in các cách chọn
void generateCombinations(int roses, int daisies, int k, int h, vector<int>& combination) {
    if (h > roses || (k - h) > daisies) return; // Kiểm tra tính hợp lệ

    if (h + combination.size() == k) { // Điều kiện dừng khi hoàn thành lựa chọn
        for (int i = 0; i < h; ++i) cout << "Rose ";
        for (int i = 0; i < (k - h); ++i) cout << "Daisy ";
        cout << endl;
        return;
    }

    // Thử thêm một bông hồng
    combination.push_back(1); // 1 biểu thị bông hồng
    generateCombinations(roses, daisies, k, h + 1, combination);
    combination.pop_back(); // Lùi lại để thử trường hợp khác

    // Thử thêm một bông cúc
    combination.push_back(0); // 0 biểu thị bông cúc
    generateCombinations(roses, daisies, k, h, combination);
    combination.pop_back(); // Lùi lại để thử trường hợp khác
}

int main() {
    int roses, daisies, k;
    cout << "Nhập số lượng hoa hồng: ";
    cin >> roses;
    cout << "Nhập số lượng hoa cúc: ";
    cin >> daisies;
    cout << "Nhập số lượng hoa cần bốc: ";
    cin >> k;

    vector<int> combination; // Lưu trạng thái
    cout << "Các cách chọn hoa:\n";
    generateCombinations(roses, daisies, k, 0, combination);

    return 0;
}
