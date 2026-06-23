class Solution {
   private:
    bool dfs(int i, string& s, vector<string>& wordDict, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        if (i == s.size()) return true;

        for (auto word : wordDict) {
            if (i + word.size() <= s.size() && s.compare(i, word.size(), word) == 0) {
                if (dfs(i + word.size(), s, wordDict, dp)) return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        return dfs(0, s, wordDict, dp);
    }
};
