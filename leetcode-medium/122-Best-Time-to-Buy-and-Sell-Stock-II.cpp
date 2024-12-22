class Solution {
public:
    // so simple, if we have the freedom to buy and sell each day, this means
    // I can make profit each time the price goes from low to heigh
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int i=1; i<prices.size(); ++i) {
            if (prices[i] > prices[i-1]) totalProfit += (prices[i] - prices[i-1]);
        }
        return totalProfit;
    }
};