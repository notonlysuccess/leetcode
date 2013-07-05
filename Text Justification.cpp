class Solution {
public:
    string gen(vector<string> &words,int L,int sum,int count,int index,bool lastLine) {
        string str;
        if (count == 0 || lastLine) {
            for (int i = 0 ; i <= count ; i ++) {
                if (i) str += " ";
                str += words[index - count - 1 + i];
            }
            for (int i = str.length() ; i < L ; i ++) {
                str += " ";
            }
        } else {
            int spaces = L - sum;
            int div = spaces / count;
            int rem = spaces % count;
            for (int i = 0 ; i <= count ; i ++) {
                if (i) {
                    str += string(div , ' ');
                    if (i <= rem) {
                        str += ' ';
                    }
                }
                str += words[index - count - 1 + i];
            }
        }
        return str;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        if (L == 0) {
            return vector<string>(1,"");
        }
        int sum = 0;
        int count = 0;
        for (int i = 0 ; i < words.size() ;i ++) {
            sum += words[i].length();
            if (sum + count > L) {
                ret.push_back( gen(words , L , sum - words[i].length() , count - 1 , i , false) );
                sum = words[i].length();
                count = 1;
            } else {
                count ++;
            }
        }
        if (count) {
            ret.push_back( gen(words , L , sum , count - 1 , words.size() , true) );
        }
        return ret;
    }
};