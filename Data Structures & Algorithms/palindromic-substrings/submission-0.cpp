class Solution {
   private:
    int expand(string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }

        return count;
    }

   public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            auto s1 = expand(s, i, i);
            auto s2 = expand(s, i, i + 1);
            count += s1 + s2;
        }

        return count;
    }
};
