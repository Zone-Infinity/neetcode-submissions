class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;

        vector<int> dp(n, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};
