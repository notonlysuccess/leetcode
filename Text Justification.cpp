class Solution {
private:
    string line(int s, int e, int L, bool last, vector<string> &word) {
        string ret;
        if (s == e || last) {
            for (int i = s ; i < e ; i ++) {
                ret += word[i] + " ";
            }
            ret += word[e];
        } else {
            int remain = L;
            for (int i = s ; i <= e ; i ++) {
                remain -= word[i].length();
            }
            int div = remain / (e - s);
            int more = remain % (e - s);
            for (int i = s ; i < e ; i ++) {
                ret += word[i] + string(div + (i < s + more) , ' ');
            }
            ret += word[e];
        }
        if (ret.length() < L) {
            ret += string(L - ret.length() , ' ');
        }
        return ret;
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int s = 0 , sum = 0;
        for (int i = 0 ; i < words.size() ; i ++) {
            if (sum + words[i].length() > L) {
                ret.push_back(line(s , i - 1 , L , false , words));
                sum = 0;
                s = i;
            }
            sum += words[i].length() + 1;
        }
        ret.push_back(line(s , words.size() - 1 , L , true , words));
        return ret;
    }
};