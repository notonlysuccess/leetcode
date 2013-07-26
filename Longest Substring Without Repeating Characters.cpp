class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lease[1<<8];
        memset(lease , -1 , sizeof(lease));
        int ret = 0 , sum = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (lease[ s[i] ] < i - sum) {
                sum ++;
            } else {
                sum = i - lease[ s[i] ];
            }
            lease[ s[i] ] = i;
            ret = max(ret , sum);
        }
        return ret;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[1<<8];
        memset(pos , -1 , sizeof(pos));
        int ret = 0 , begin = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            begin = max(begin , pos[s[i]] + 1);
            pos[s[i]] = i;
            ret = max(ret , i - begin + 1);
        }
        return ret;
    }
};