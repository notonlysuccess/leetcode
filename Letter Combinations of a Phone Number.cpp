class Solution {
private:
    void dfs(vector<string> &ret , string &temp , string &digits , int index) {
        if (index == digits.length()) {
            ret.push_back(temp);
            return ;
        }
        const static char character[][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int dig = digits[index] - '0';
        for (int i = 0 ; character[dig][i] ; i ++) {
            temp[index] = character[dig][i];
            dfs(ret , temp , digits , index + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string temp(digits.length() , ' ');
        dfs(ret , temp , digits , 0);
        return ret;
    }
};