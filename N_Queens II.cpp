class Solution {
private:
    int NQueens(int m,int l,int r,int mask) {
        if (m == mask) {
            return 1;
        }
        int ret = 0;
        for (int can = mask & ~(m|l|r) ; can ; can &= (can-1)) {
            int b = can&(-can);
            ret += NQueens(m|b , (l|b)<<1 , (r|b)>>1 , mask);
        }
        return ret;
    }
public:
    int totalNQueens(int n) {
        return NQueens(0 , 0 , 0 , (1<<n) - 1);
    }
};