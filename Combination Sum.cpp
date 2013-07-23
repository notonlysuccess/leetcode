class Solution {
private:
    void comb(vector<vector<int> >&ret , vector<int> &temp , vector<int> &num, int index, int target) {
        if (target == 0) {
            ret.push_back(temp);
            return ;
        }
        for (int i = index ; i < num.size() ; i ++) {
            if (num[i] <= target) {
                temp.push_back(num[i]);
                comb(ret , temp , num , i ,target - num[i]);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> temp;
        sort(num.begin() , num.end());
        comb(ret , temp , num , 0 , target);
        return ret;
    }
};