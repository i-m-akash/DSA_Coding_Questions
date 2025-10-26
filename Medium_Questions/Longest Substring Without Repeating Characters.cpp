## 🧩 Problem Summary

Given a string `s`, find the **length of the longest substring** (continuous characters) that has **no repeating characters**.

---

### Example

| Input        | Output | Explanation        |
| ------------ | ------ | ------------------ |
| `"abcabcbb"` | `3`    | `"abc"` or `"bca"` |
| `"bbbbb"`    | `1`    | `"b"`              |
| `"pwwkew"`   | `3`    | `"wke"`            |

---

## ✅ Optimal Solution — Sliding Window + Hash Map

We use **two pointers (left and right)** to maintain a window of unique characters, and a **hash map** to store the last seen index of each character.

### 🔹 Intuition:

* Expand the window by moving `right`.
* If a character repeats, shrink the window from the left until the duplicate is removed.
* Track the maximum window size during the process.

---

### 🧠 Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen; // store last seen index of each char
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); ++right) {
        char c = s[right];

        // If char is already seen and inside current window
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            left = lastSeen[c] + 1; // move left pointer past the duplicate
        }

        lastSeen[c] = right; // update last seen position
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<string> testCases = {"abcabcbb", "bbbbb", "pwwkew", ""};

    for (string s : testCases) {
        cout << "Input: " << s << " -> Output: " << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
```

---

### 🕒 Time Complexity:

* **O(n)** — Each character is visited at most twice (once by `right`, once by `left`).

### 💾 Space Complexity:

* **O(min(n, charset))** — For storing last seen positions in hash map (charset ≤ 128 for ASCII).

---

### ⚡ Example Dry Run:

`s = "pwwkew"`

| Step | Right | Char | Action                     | Left | Window | MaxLen |
| ---- | ----- | ---- | -------------------------- | ---- | ------ | ------ |
| 0    | 0     | p    | Add p                      | 0    | "p"    | 1      |
| 1    | 1     | w    | Add w                      | 0    | "pw"   | 2      |
| 2    | 2     | w    | Duplicate → move left to 2 | 2    | "w"    | 2      |
| 3    | 3     | k    | Add k                      | 2    | "wk"   | 2      |
| 4    | 4     | e    | Add e                      | 2    | "wke"  | 3      |
| 5    | 5     | w    | Duplicate → move left to 3 | 3    | "kew"  | 3      |

✅ **Answer = 3**


