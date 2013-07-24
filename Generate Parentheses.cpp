class Solution {
private:
    void dfs(vector<string> &vec , string &str , int left,int right,int n) {
        if (right == n) {
            vec.push_back(str);
            return ;
        }
        if (left < n) {
            str[left+right] = '(';
            dfs(vec , str , left + 1 , right , n);
        }
        if (right < n && right < left) {
            str[left+right] = ')';
            dfs(vec , str , left , right + 1 , n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string str(2*n , ' ');
        dfs(vec , str , 0 , 0 , n);
        return vec;
    }
};