class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int sc[26];
        int tc[26];
        for(int i = 0; i < 26; i++) {
            sc[i] = 0;
            tc[i] = 0;
        }
        for(int i = 0; i < s.length(); i++) {
            sc[((int) s[i]) - 97]++;
            tc[((int) t[i]) - 97]++;
        }
        
        for(int i = 0; i < 26; i++) {    
            if(sc[i] != tc[i]) return false;
        }

        return true;
    }
};
