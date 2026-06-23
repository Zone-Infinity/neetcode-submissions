class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n2 < n1) return false;
        
        for(int i = 0; i < n2 - n1 + 1; i++) {            
            vector<int> alpha(26, 0);
            for(char c : s1) alpha[c - 'a']++;

            for(int j = i; j < i + n1; j++) {
                alpha[s2[j] - 'a']--;
            }

            bool flag = false;
            for(int a : alpha) {
                if(a != 0) {
                    flag = true;
                    break;
                }
            }

            if(flag) continue;
            else return true;
        }

        return false;
    }
};
