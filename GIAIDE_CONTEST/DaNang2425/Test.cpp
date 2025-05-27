#include<bits/stdc++.h>

using namespace std;

bool canHaveMedian(const vector<int>& arr, int K, int x) {
    int N = arr.size();
    vector<int> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + (arr[i] >= x ? 1 : -1);
    }

    int min_prefix = 0;
    for (int i = K; i <= N; ++i) {
        if (prefix[i] - min_prefix > 0) {
            return true;
        }
        min_prefix = min(min_prefix, prefix[i - K + 1]);
    }
    return false;
}

int findMaxMedian(vector<int>& arr, int K) {
    int left = *min_element(arr.begin(), arr.end());
    int right = *max_element(arr.begin(), arr.end());
    int ans = left;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canHaveMedian(arr, K, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cout << findMaxMedian(arr, K) << endl;
    return 0;
}
