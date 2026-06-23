class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mid == 0) return min(nums[0], nums[1]);
            if(nums[mid - 1] > nums[mid]) return nums[mid];
            else if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid - 1;
        }

        return nums[l];
    }
};
