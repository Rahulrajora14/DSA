class Solution {
    int dp[2501][2501];  // FIXED SIZE

    int help(int i, int prev, vector<int> &nums, int n){
        if(i == n) return 0;

        if(dp[i][prev + 1] != -1) 
            return dp[i][prev + 1];

        // skip
        int len = help(i + 1, prev, nums, n);

        // take
        if(prev == -1 || nums[i] > nums[prev]){
            len = max(len, 1 + help(i + 1, i, nums, n));
        }

        return dp[i][prev + 1] = len;  // ALWAYS STORE
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return help(0, -1, nums, nums.size());
    }
};