class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, ans = INT_MAX, cnt = 0, n = nums.size();
        while(j < n)
        {
            cnt += nums[j];
            while(cnt >= target)
            {
                ans = min(ans, j-i+1);
                cnt -= nums[i];
                i++;   
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
