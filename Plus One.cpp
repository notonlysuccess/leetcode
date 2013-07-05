class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin() , digits.end());
        bool carry = true;
        for (int i = 0 ; i < digits.size() && carry; i ++) {
            digits[i] ++;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                carry = false;
            }
        }
        if (carry) {
            digits.push_back(1);
        }
        reverse(digits.begin() , digits.end());
        return digits;
    }
};