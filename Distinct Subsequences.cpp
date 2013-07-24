class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.length();
        int m = T.length();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j <= m ; j ++) {
                if (S[i] == T[j]) {
                    dp[i+1][j+1] += dp[i][j];
                }
                dp[i+1][j] += dp[i][j];
            }
        }
        return dp[n][m];
    }
};