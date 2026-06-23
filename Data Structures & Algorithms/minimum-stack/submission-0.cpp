class MinStack {
   private:
    stack<pair<int, int>> st;

   public:
    MinStack() {}

    void push(int val) {
        int minV = st.empty() ? val : min(st.top().second, val);
        st.push({val, minV});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};
