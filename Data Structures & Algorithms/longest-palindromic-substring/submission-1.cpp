class Solution {
   private:
    pair<int, int> expand(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        return {l + 1, r - 1};
    }

   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 0, maxR = 0;
        for (int i = 0; i < n; i++) {
            auto s1 = expand(s, i, i);
            auto s2 = expand(s, i, i + 1);
            pair<int, int> p;
            if (s1.second - s1.first < s2.second - s2.first) {
                p.second = s2.second;
                p.first = s2.first;
            } else {
                p.second = s1.second;
                p.first = s1.first;
            }

            if (maxR - maxL < p.second - p.first) {
                maxR = p.second;
                maxL = p.first;
            }
        }

        return s.substr(maxL, maxR - maxL + 1);
    }
};
