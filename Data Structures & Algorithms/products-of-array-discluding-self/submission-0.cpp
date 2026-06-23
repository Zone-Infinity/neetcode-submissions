class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long n = nums.size();
        vector<int> prefixProd(n);
        vector<int> suffixProd(n);

        prefixProd[0] = nums[0];
        suffixProd[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
            suffixProd[n - i - 1] = suffixProd[n - i] * nums[n - i - 1];
        }

        vector<int> output(n);

        for(int i = 0; i < n; i++) {
            int pref = i - 1 < 0 ? 1 : prefixProd[i - 1];
            int suff = i + 1 > n - 1 ? 1 : suffixProd[i + 1];
            output[i] = pref * suff;
        }

        return output;
    }
};
