class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int best = 0;
        int smallest = 0x7fffffff;
        for (int i = 0 ; i < prices.size() ; i ++) {
            smallest = min(smallest , prices[i]);
            best = max(best , prices[i] - smallest);
        }
        return best;
    }
};