class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for (int i = num.size() - 1 ; i > 0 ; i --) {
            if (num[i] > num[i-1]) {
                for (int j = num.size() - 1 ;  ; j --) {
                    if (num[j] > num[i-1]) {
                        swap(num[j] , num[i-1]);
                        reverse(num.begin() + i , num.end());
                        return ;
                    }
                }
            }
        }
        reverse(num.begin() , num.end());
    }
};