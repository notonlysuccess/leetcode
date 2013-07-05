class Solution {
public:
    int dfs(int index,int left,int mid,int right,int n) {
        if (index == n) {
            return 1;
        }
        int state = (left | mid | right);
        int ret = 0;
        for (int i = 0 ; i < n ; i ++) {
            int msk = 1<<i;
            if (state & msk) continue;
            ret += dfs(index + 1 , (left | msk)<<1 , (mid | msk) , (right | msk) >> 1 , n);
        }
        return ret;
    }
    int totalNQueens(int n) {
        dfs(0 , 0 , 0 , 0 , n);
    }
};