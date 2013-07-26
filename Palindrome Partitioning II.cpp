class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> vec(s.length() , vector<int>());
        for (int i = 0 ; i < s.length() ; i ++) {
            for (int j = 0 ; i - j >= 0 && i + j < s.length() && s[i-j] == s[i+j]; j ++) {
                vec[i-j].push_back(i+j);
            }
            for (int j = 0 ; i - j >= 0 && i + j + 1 < s.length() && s[i-j] == s[i+j+1]; j ++) {
                vec[i-j].push_back(i+j+1);
            }
        }
        vector<int> dp(s.length() , INT_MAX);
        dp[0] = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            dp[i+1] = min(dp[i+1] , dp[i] + 1);
            for (int j = 0 ; j < vec[i].size() ; j ++) {
                dp[ vec[i][j]+1 ] = min(dp[ vec[i][j]+1 ] , dp[i] + 1);
            }
        }
        return dp[s.length()] - 1;
    }
}; 