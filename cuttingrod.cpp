class Solution {
public:
    int solve(int n, vector<int>& price, vector<int>& dp) {
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, price[i] + solve(n - (i + 1), price, dp));
        }

        return dp[n] = ans;
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n + 1, -1);
        return solve(n, price, dp);
    }
};