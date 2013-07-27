class Solution {
public:
    string getPermutation(int n, int k) {
        string num = "123456789";
        int d = 1;
        for (int i = 1 ; i <= n ; i ++) {
            d *= i;
        }
        string ret;
        for (int i = n ; i > 0 ; i --) {
            d /= i;
            int index = (k - 1)/d;
            k -= index*d;
            ret.push_back(num[index]);
            num.erase(num.begin() + index);
        }
        return ret;
    }
};