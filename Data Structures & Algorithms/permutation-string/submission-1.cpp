class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n2 < n1) return false;

        vector<int> alpha(26, 0);

        for(int i = 0; i < n1; i++) {
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;
        }

        if(allZero(alpha)) return true;

        for(int i = n1; i < n2; i++) {  
            alpha[s2[i - n1] - 'a']++;
            alpha[s2[i] - 'a']--;

            if(allZero(alpha)) return true;
        }

        return false;
    }

private:
    bool allZero(vector<int>& alpha) {
        for (int count : alpha) {
            if (count != 0)
                return false;
        }
        return true;
    }
};
