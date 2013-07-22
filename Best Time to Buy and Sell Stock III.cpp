class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> pre(n,0);
        int best = 0;
        int smallest = INT_MAX;
        for (int i = 0 ; i < prices.size() ; i ++) {
            smallest = min(prices[i], smallest);
            best = max(best , prices[i] - smallest);
            pre[i] = best;
        }
        int biggest = 0;
        for (int i = n - 1 ; i > 0 ; i --) {
            biggest = max(prices[i] , biggest);
            best = max(best , biggest - prices[i] + pre[i-1]);
        }
        return best;
    }
};