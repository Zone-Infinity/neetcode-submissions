class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        unordered_map<int, int> n(s);

        for(int i = 0; i < s; i++) {
            n[nums[i]] = i;
        }

        for(int i = 0; i < s; i++) {
            if(n.count(target - nums[i]) > 0 && i != n[target-nums[i]])
                return {i, n[target - nums[i]]};
        }

        return {};
    }
};
