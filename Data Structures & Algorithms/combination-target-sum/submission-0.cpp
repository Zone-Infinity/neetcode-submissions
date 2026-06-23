class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> combo;

    void dfs(vector<int>& nums, int target, int index) {
        if (target == 0) {
            ans.push_back(combo);
            return;
        }
        if (target < 0 || nums.size() == index) return;

        combo.push_back(nums[index]);
        dfs(nums, target - nums[index], index);
        combo.pop_back();
        dfs(nums, target, index + 1);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return ans;
    }
};
