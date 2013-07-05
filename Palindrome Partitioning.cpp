class Solution {
public:
	void dfs(vector<vector<string> > &ret , vector<vector<int> > &vec , int pos,int n,vector<string> &temp,string &s) {
		if (pos == n) {
			ret.push_back(temp);
			return ;
		}
		for (int i = 0 ; i < vec[pos].size() ; i ++) {
			int next = vec[pos][i] + 1;
			temp.push_back(s.substr(pos , next - pos));
			dfs(ret , vec , next , n , temp , s);
			temp.pop_back();
		}
	}
	vector<vector<string> > partition(string s) {
		int n = s.length();
		vector<vector<int> > vec;
		for (int i = 0 ; i < n ; i ++) {
			vec.push_back(vector<int>());
		}
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; i - j >= 0 && i + j < n && s[i-j] == s[i+j]; j ++) {
				vec[i-j].push_back(i+j);
			}
		}
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; i - j >= 0 && i + j + 1 < n && s[i-j] == s[i+j+1] ; j ++) {
				vec[i-j].push_back(i+j+1);
			}
		}
		vector<vector<string> > ret;
		vector<string> temp;
		dfs(ret , vec , 0 , n , temp , s);
		return ret;
	}
};