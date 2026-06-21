class Solution {
public:
    bool allZero(vector<int>& cnt) {
        for (int x : cnt) {
            if (x != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int k = p.size();

        if (k > n) return ans;

        vector<int> cnt(26, 0);

        for (char c : p) {
            cnt[c - 'a']++;
        }

        int i = 0, j = 0;

        while (j < n) {
            cnt[s[j] - 'a']--;

            if (j - i + 1 == k) {
                if (allZero(cnt)) {
                    ans.push_back(i);
                }

                cnt[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return ans;
    }
};
