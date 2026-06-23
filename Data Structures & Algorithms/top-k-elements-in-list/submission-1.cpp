class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n : nums) freq[n]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto f : freq) {
            bucket[f.second].push_back(f.first);
        }

        vector<int> ans;
        int count = 0;
        for(int i = nums.size(); i >= 0; i--) {
            if(!bucket[i].empty()) {
                for(int b : bucket[i])
                    if(count++ < k)
                        ans.push_back(b);
            }
        }

        return ans;
    }
};
