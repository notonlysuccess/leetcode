class Solution {
public:
    void dfs(vector<string> &ret ,string &s,const string &temp, int dots,int index,int val) {
        if (val > 255 || dots == 4) {
            return ;
        }
        if (index == s.length()) {
            if (dots == 3 && val != -1) {
                ret.push_back(temp);
            }
            return ;
        }
        if (val != -1) {
            dfs(ret , s , temp + '.' , dots + 1 , index , -1);
        }
        if (val == 0) {
            return ;
        }
        if (val == -1) {
            val = 0;
        }
        dfs(ret , s , temp + s[index] , dots , index + 1 , val * 10 + s[index] - '0');
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        dfs(ret , s , "" , 0 , 0 , -1);
        return ret;
    }
};