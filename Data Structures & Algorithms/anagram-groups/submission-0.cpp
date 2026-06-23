class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> groups;

        for(string s : strs) {
            array<int, 26> chars = {};
            for(char c : s) {
                chars[c - 'a']++;
            }

            groups[chars].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto v : groups) {
            ans.push_back(v.second);
        }

        return ans;
    }
};
