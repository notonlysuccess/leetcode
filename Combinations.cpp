class Solution {
public:
	void dfs(int n,int k,int start,int kk,vector<vector<int> > &ret , vector<int> &temp) {
		if (kk == k) {
			ret.push_back(temp);
			return ;
		}
		for (int i = start ; i < n ; i ++) {
			temp[kk] = i + 1;
			dfs(n , k , i + 1 , kk + 1 , ret , temp);
		}
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ret;
		vector<int> temp(k,0);
		dfs(n , k , 0 , 0 , ret , temp);
		return ret;
	}
};