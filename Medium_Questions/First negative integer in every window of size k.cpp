#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> firstNegative(vector<int>& arr, int k) {
    vector<int> result;
    queue<int> q; // stores indices of negative numbers

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        // Store index if element is negative
        if (arr[i] < 0) {
            q.push(i);
        }

        // Remove elements out of current window
        while (!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        // Window starts after k-1 index
        if (i >= k - 1) {

            if (!q.empty()) {
                result.push_back(arr[q.front()]);
            } else {
                result.push_back(0);
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegative(arr, k);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
