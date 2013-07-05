class Solution {
public:
	void dfs(vector<int> &num,int target,int start,set<vector<int> > &ret,vector<int> &temp) {
		if (target == 0) {
			ret.insert(temp);
			return ;
		}
		for (int i = start ; i < num.size() ; i ++) {
			if (num[i] > target) break;
			temp.push_back(num[i]);
			dfs(num , target - num[i] , i , ret , temp);
			temp.pop_back();
		}
	}
	vector<vector<int> > combinationSum(vector<int> &num, int target) {
		set<vector<int> > ret;
		vector<int> temp;
		sort(num.begin() , num.end());
		dfs(num , target , 0 , ret , temp);
		return vector<vector<int> >(ret.begin() , ret.end());
	}
};