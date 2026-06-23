class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        unordered_map<int, int> n(s);

        for(int i = 0; i < s; i++) {
            n[nums[i]] = i;
        }

        for(int i = 0; i < s; i++) {
            int diff = target - nums[i];
            if(n.count(diff) > 0 && i != n[diff])
                return {i, n[diff]};
        }

        return {};
    }
};
