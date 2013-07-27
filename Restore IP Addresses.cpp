class Solution {
private:
    vector<string> ret;
    void dfs(int dot, int val, int index, string &s , const string &ip) {
        if (dot == 4 || val > 255) {
            return ;
        }
        if (index == s.length()) {
            if (dot == 3 && val != -1) {
                ret.push_back(ip);
            }
            return ;
        }
        if (val != -1) {
            dfs(dot+1, -1, index, s, ip+'.');
        }
        if (val == 0) {
            return ;
        }
        if (val == -1) {
            val = 0;
        }
        dfs(dot , val * 10 + s[index] - '0' , index + 1 , s , ip + s[index]);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ret.clear();
        dfs(0, -1, 0, s , "");
        return ret;
    }
};