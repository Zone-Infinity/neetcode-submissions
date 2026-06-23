class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!left.empty()) {
                    left.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else
                    return false;
            }
        }

        while (!left.empty() && !star.empty() && left.top() < star.top()) {
            left.pop();
            star.pop();
        }

        if (!left.empty() && star.empty()) return false;

        return true;
    }
};
