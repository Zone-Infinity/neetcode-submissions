class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;

        for(int n : nums2) {
            while(!st.empty() && st.top() < n) {
                nextGreater[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        while(!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> res;
        for(int n : nums1) res.push_back(nextGreater[n]);

        return res;
    }
};