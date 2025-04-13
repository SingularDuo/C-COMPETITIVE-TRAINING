#include<bits/stdc++h>

using namespace std;

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int K;
    cin >> K;

    vector<int> perfect_numbers;
    int num = 1; 

    while (perfect_numbers.size() < K) {
        if (sum_of_digits(num) == 10) {
            perfect_numbers.push_back(num);
        }
        num++;
    }

    cout << perfect_numbers[K - 1] << endl;
    return 0;
}
