class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int ans = 0;
		int Min = 0x7fffffff;
		for (int i = 0 ; i < prices.size() ; i ++) {
			Min = min(prices[i] , Min);
			ans = max(ans , prices[i] - Min);
		}
		return ans;
	}
};