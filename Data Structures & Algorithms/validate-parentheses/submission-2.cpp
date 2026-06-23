class Solution {
public:
    bool isValid(string s) {
        stack<char> par;

        for(char c : s) {
            if(c == ')') {
                if(!par.empty() && par.top() == '(') par.pop();
                else return false;
            }

            else if(c == ']') {
                if(!par.empty() && par.top() == '[') par.pop();
                else return false;
            }

            else if(c == '}') {
                if(!par.empty() && par.top() == '{') par.pop();
                else return false;
            }

            else par.push(c);
        }

        return par.empty();
    }
};
