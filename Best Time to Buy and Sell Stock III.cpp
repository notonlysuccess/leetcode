class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		vector<int> dp(n , 0);
		int Min = 0x7fffffff;
		for (int i = 0 ; i < n ; i ++) {
			Min = min(Min , prices[i]);
			dp[i] = prices[i] - Min;
			if (i) dp[i] = max(dp[i] , dp[i-1]);
		}
		int Max = 0;
		int ret = 0;
		for (int i = n - 1 ; i >= 0 ; i --) {
			Max = max(Max , prices[i]);
			ret = max(ret , dp[i] + Max - prices[i]);
		}
		return ret;
	}
};