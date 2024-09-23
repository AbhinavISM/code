#include <bits/stdc++.h>
using namespace std;

vector<long long> longestSubsequence(int N, int K, vector<vector<long long>> A) {
    // Step 1: Use a difference array to handle range updates
    vector<long long> diff(200000, 0); // Assumes maximum possible R value within the problem constraints
    for (const auto &query : A) {
        int L = query[0], R = query[1], X = query[2];
        diff[L] += X;
        if (R + 1 < diff.size()) {
            diff[R + 1] -= X;
        }
    }

    // Step 2: Calculate the actual array values after applying all updates
    vector<long long> arr(200000, 0);
    arr[0] = diff[0];
    for (int i = 1; i < arr.size(); ++i) {
        arr[i] = arr[i - 1] + diff[i];
    }

    // Step 3: Find the lexicographically smallest and longest increasing subsequence
    int maxLength = 0;
    int startZ = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int currentLength = 0;
        int currentValue = i;
        while (currentValue < arr.size() && arr[currentValue] > 0) {
            currentLength++;
            currentValue += K;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
            startZ = i;
        }
    }

    // Prepare the result
    vector<long long> result;
    result.push_back(maxLength);
    for (int i = 0; i < maxLength; ++i) {
        result.push_back(startZ + i * K + 1); // +1 for 1-based indexing
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int K;
    cin >> K;

    vector<vector<long long>> A(N, vector<long long>(3));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    vector<long long> out_ = longestSubsequence(N, K, A);

    cout << out_[0];
    for (size_t i = 1; i < out_.size(); ++i) {
        cout << " " << out_[i];
    }
    cout << "\n";

    return 0;
}