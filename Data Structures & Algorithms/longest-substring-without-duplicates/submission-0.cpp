class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int l = 0, r = 0, n = s.length();
        int longest = 0;

        while(r < n) {
            if(hash[s[r]]) {
                hash[s[l++]]--;
                continue;
            }

            hash[s[r++]]++;
            longest = max(longest, r - l);
        }

        return longest;
    }
};
