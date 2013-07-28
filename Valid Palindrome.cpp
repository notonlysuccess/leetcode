class Solution {
public:
    bool isPalindrome(string s) {
        for (int lo = 0, hi = s.length() - 1 ; lo < hi ;) {
            if (!isalnum(s[lo])) {
                lo ++;
            } else if (!isalnum(s[hi])) {
                hi --;
            } else if (toupper(s[lo++]) != toupper(s[hi--])) {
                return false;
            }
        }
        return true;
    }
};