class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            minP = min(minP, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minP);
        }

        return maxProfit;
    }
};
