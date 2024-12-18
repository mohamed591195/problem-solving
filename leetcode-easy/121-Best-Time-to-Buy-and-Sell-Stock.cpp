// we can use kadane's algorithm to solve this question
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit = 0, maxProfit = 0;

        for(int i=1; i<prices.size(); ++i) {
            currProfit += prices[i] - prices[i-1];
            currProfit = max(currProfit, 0);
            maxProfit = max(maxProfit, currProfit);
        }

        return maxProfit;
    }
};