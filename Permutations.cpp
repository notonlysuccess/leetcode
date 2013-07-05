class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin() , num.end());
        vector<vector<int> > ret;
        bool flag = true;
        while (flag) {
            ret.push_back(num);
            flag = false;
            for (int i = num.size() - 2 ; i >= 0 ; i --) {
                if (num[i] < num[i+1]) {
                    flag = true;
                    for (int j = num.size() - 1 ; j > i ; j --) {
                        if (num[i] < num[j]) {
                            swap(num[i] , num[j]);
                            reverse(num.begin() + i + 1 , num.end());
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ret;
    }
};