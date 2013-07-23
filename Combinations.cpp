class Solution {
private:
    void comb(vector<vector<int> >&ret , vector<int> &temp,int n,int k) {
        if (k == 0) {
            ret.push_back(temp);
            return ;
        }
        for (int i = k ; i <= n ; i ++) {
            temp[k-1] = i;
            comb(ret , temp , i - 1 , k - 1);
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> temp(k,0);
        comb(ret , temp , n , k);
        return ret;
    }
};