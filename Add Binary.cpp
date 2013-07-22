class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        for ( ; i >= 0 || j >= 0 || carry ; i -- , j --) {
            int a_val = i >= 0 ? a[i] - '0' : 0;
            int b_val = j >= 0 ? b[j] - '0' : 0;
            int sum = a_val + b_val + carry;
            carry = sum >> 1;
            c.insert(c.begin() , '0' + (sum&1));
        }
        return c;
    }
};