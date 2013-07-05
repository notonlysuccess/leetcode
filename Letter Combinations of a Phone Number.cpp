class Solution {
public:
    void dfs(string &digits , int id,vector<string> &ret , const string &temp) {
    	if (id == digits.size()) {
			ret.push_back(temp);
			return ;
		}
		char chars[][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for (int i = 0 ; chars[digits[id] - '0'][i] ; i ++) {
			dfs(digits , id + 1 , ret , string(temp + chars[digits[id] - '0'][i]));
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		dfs(digits , 0 ,  ret , string(""));
		return ret;
	}
};