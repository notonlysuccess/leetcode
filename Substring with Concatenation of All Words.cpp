/*
unordered_map 160ms
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.size() == 0) {
            return ret;
        }
        unordered_map<string,int> dict;
        for (int i = 0 ; i < L.size() ; i ++) {
            dict[ L[i] ] ++;
        }
        int l = L[0].size();
        int total = l * L.size();
        for (int i = 0 ; i < l ; i ++) {
            unordered_map<string,int> get;
            int count = 0;
            int start = i;
            for (int j = i ; j < S.length() ; j += l) {
                string substr = S.substr(j , l);
                unordered_map<string,int>::iterator iter = dict.find(substr);
                if (iter != dict.end()) {
                    unordered_map<string,int>::iterator iter2 = get.find(substr);
                    if (iter2 == get.end()) {
                        iter2 = get.insert(make_pair(substr,0)).first;
                    }
                    iter2->second ++;
                    if (iter2->second == iter->second) {
                        count ++;
                    }
                    if (j >= total + start) {
                        substr = S.substr(j - total , l);
                        iter = dict.find(substr);
                        iter2 = get.find(substr);
                        if (iter->second == iter2->second) {
                            count --;
                        }
                        iter2->second --;
                    }
                    if (count == dict.size()) {
                        ret.push_back(j - total + l);
                    }
                } else {
                    start = j + l;
                    get.clear();
                    count = 0;
                }
            }
        }
        return ret;
    }
};