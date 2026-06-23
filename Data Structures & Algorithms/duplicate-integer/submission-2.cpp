class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> n;

        for(int i = 0; i < nums.size(); i++)
            n.insert(nums[i]);
        
        return n.size() != nums.size();
    }
};