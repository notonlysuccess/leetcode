class Solution {
public:
	int dp[111111];
	void checkmin(int &a,int b) {
		if (a == -1 || a > b) a = b;
	}
    int minCut(string s) {
        vector<vector<int>> vec;
        for (int i = 0 ; i < s.length() ; i ++) {
        	vec.push_back(vector<int>());
        }
        for (int i = 0 ; i < s.length() ; i ++) {
        	for (int j = 0 ; i - j >= 0 && i + j < s.length() && s[i-j] == s[i+j]; j ++) {
        		vec[i-j].push_back(i+j);
        	}
        	for (int j = 0 ; i - j >= 0 && i + j + 1 < s.length() && s[i-j] == s[i+j+1]; j ++) {
        		vec[i-j].push_back(i+j+1);
        	}
        }
        memset(dp , -1 , sizeof(dp));
        dp[0] = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
        	checkmin(dp[i+1] , dp[i] + 1);
        	for (int j = 0 ; j < vec[i].size() ; j ++) {
        		checkmin(dp[ vec[i][j]+1 ] , dp[i] + 1);
        	}
        }
        return dp[s.length()] - 1;
    }
};