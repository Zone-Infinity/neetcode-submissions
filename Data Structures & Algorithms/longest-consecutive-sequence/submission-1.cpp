class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());

        int maxLen = 0;

        for(int n : hash) {
            if(!hash.count(n - 1)) {
                int len = 1;
                int cur = n;

                while(hash.count(cur + 1)) {
                    cur++;
                    len++;
                }

                maxLen = max(len, maxLen);
            }
        }

        return maxLen;
    }
};
