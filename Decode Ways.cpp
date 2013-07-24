class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (i && (s[i-1] - '0') * 10 + (s[i] - '0') <= 26 && s[i-1] != '0') {
                dp[i+1] += dp[i-1];
            }
            if (s[i] != '0') {
                dp[i+1] += dp[i];
            }
        }
        return dp[n];
    }
};