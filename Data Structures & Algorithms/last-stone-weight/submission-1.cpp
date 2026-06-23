class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int st : stones) pq.push(st);

        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            if(s1 == s2) continue;
            if(s1 > s2) pq.push(s1 - s2);
            else pq.push(s2 - s1);
        }

        return pq.empty()? 0: pq.top();
    }
};
