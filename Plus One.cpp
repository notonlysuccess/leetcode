class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        for (int i = digits.size() - 1 ; carry && i >= 0 ; i --) {
            digits[i] ++;
            carry = digits[i] > 9;
            digits[i] %= 10;
        }
        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};