class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while(i < n - 1) {
            if(nums[i] == 0) return false;
            i += nums[i];
        }

        return true;
    }
};
