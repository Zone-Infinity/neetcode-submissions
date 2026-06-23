class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;

        for(string c : tokens) {
            if(c == "+") {
                int s = ans.top(); ans.pop();
                s += ans.top(); ans.pop();
                ans.push(s);
            }
            else if(c == "-") {
                int s = ans.top(); ans.pop();
                s -= ans.top(); ans.pop();
                ans.push(-s);
            }
            else if(c == "*") {
                int s = ans.top(); ans.pop();
                s *= ans.top(); ans.pop();
                ans.push(s);
            }
            else if(c == "/") {
                int a = ans.top(); ans.pop();
                int b = ans.top(); ans.pop();
                ans.push(b / a);
            }
            else {
                ans.push(stoi(c));
            }
        }

        return ans.top();
    }
};
