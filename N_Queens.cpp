class Solution {
public:
    void dfs(int index,int left,int mid ,int right,int n,vector<string> &temp , vector<vector<string> > &ret) {
        if (index == n) {
            ret.push_back(temp);
            return ;
        }
        for (int i = 0 , pos = 1 ; i < n ; pos <<= 1 , i ++) {
            if (pos & (left | mid | right)) continue;
            temp[index][i] = 'Q';
            dfs(index + 1 , (left | pos) << 1 , mid | pos , (right | pos) >> 1 , n , temp , ret);
            temp[index][i] = '.';
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        vector<string> temp(n , string(n,'.'));
        dfs(0 , 0 , 0 , 0 , n , temp , ret);
        return ret;
    }
};