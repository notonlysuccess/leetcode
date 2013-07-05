class Solution {
public:
    void dfs(int left,int right,int n,vector<string> &ret,const string &ans) {
		if (right == n) {
			ret.push_back(ans);
			return ;
		}
		if (left < n) {
			dfs(left + 1 , right , n , ret , ans + '(');
		}
		if (right < left) {
			dfs(left , right + 1 , n , ret , ans + ')');
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		dfs(0 , 0 , n , ret , "");
		return ret;
	}
};