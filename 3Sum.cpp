class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin() , num.end());
        vector<vector<int>> ret;
        for (int i = 0 ; i < num.size() ; i ++) {
            if (i && num[i] == num[i-1]) {
                continue;
            }
            int lo = i + 1;
            int hi = num.size() - 1;
            while (lo < hi) {
                int sum = num[i] + num[lo] + num[hi];
                if (sum < 0) {
                    lo ++;
                } else if (sum == 0) {
                    ret.push_back(vector<int>({num[i] , num[lo] , num[hi]}));
                    lo ++;
                    hi --;
                    while (lo < hi && num[lo] == num[lo-1]) {
                        lo ++;
                    }
                    while (lo < hi && num[hi] == num[hi+1]) {
                        hi --;
                    }
                } else {
                    hi --;
                }
            }
        }
        return ret;
    }
};