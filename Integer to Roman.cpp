class Solution {
public:
    string intToRoman(int num) {
        char one[] = "IXCM";
        char five[] = "VLD";
        string ret;
        for (int i = 0 , dig = num % 10; num ; i ++ , num /= 10) {
            if (dig <= 3) {
                ret = string(dig , one[i]) + ret;
            } else if (dig <= 5) {
                ret = string(5-dig , one[i]) + five[i] + ret;
            } else if (dig <= 8) {
                ret = five[i] + string(dig - 5 , one[i]) + ret;
            } else {
                ret = string(1 , one[i]) + one[i+1] + ret;
            }
        }
        return ret;
    }
};