# Problem (brief)

Given an array `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.
Assume exactly one solution exists and you may not use the same element twice.

---

# Approach 1 — Hash map (best: O(n))

Use an unordered_map to store value → index while scanning. For each element `x`, check if `target - x` exists in the map.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Returns indices of the two numbers that add up to target.
// If no pair found, returns empty vector.
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int,int> idx; // value -> index
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];
        auto it = idx.find(need);
        if (it != idx.end()) {
            return {it->second, i}; // found: index of 'need' and current index
        }
        idx[nums[i]] = i;
    }
    return {}; // no solution (problem usually guarantees one)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto res = twoSum(nums, target);
    if (!res.empty()) {
        cout << "Indices: " << res[0] << ", " << res[1] << '\n';
        cout << "Values: " << nums[res[0]] << " + " << nums[res[1]] << " = " << target << '\n';
    } else {
        cout << "No pair found.\n";
    }
    return 0;
}
```

**Time complexity:** O(n) average
**Space complexity:** O(n)

---

# Approach 2 — Two pointers (O(n log n) due to sort)

If you are allowed to **return values** (not original indices) or you can sort a copy with indices, two-pointer on a sorted array works. This is useful when you prefer less extra memory (besides sort).

```cpp
#include <bits/stdc++.h>
using namespace std;

// Returns original indices of two numbers summing to target,
// using sort+two-pointer. O(n log n) time.
vector<int> twoSumSorted(vector<int> nums, int target) {
    int n = nums.size();
    vector<pair<int,int>> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) arr.emplace_back(nums[i], i);
    sort(arr.begin(), arr.end()); // sort by value

    int l = 0, r = n - 1;
    while (l < r) {
        int sum = arr[l].first + arr[r].first;
        if (sum == target) {
            return {arr[l].second, arr[r].second}; // original indices
        } else if (sum < target) ++l;
        else --r;
    }
    return {};
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    auto res = twoSumSorted(nums, target);
    if (!res.empty()) {
        cout << "Indices: " << res[0] << ", " << res[1] << '\n';
    } else {
        cout << "No pair found.\n";
    }
    return 0;
}
```

**Time complexity:** O(n log n) (sort)
**Space complexity:** O(n) (for index pairs)

---

# Notes & edge cases

* If duplicates exist (e.g., `[3,3]` target 6), the hash-map approach handles it because map stores previous index and will find the pair.
* If indices order matters (smaller index first), you can sort the resulting pair before returning/printing.
* Use 64-bit types if numbers/target can exceed `int`.

---

