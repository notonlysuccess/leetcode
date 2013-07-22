class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,vector<string>> mp;
        for (int i = 0 ; i < strs.size() ; i ++) {
            string key = strs[i];
            sort(key.begin() , key.end());
            mp[key].push_back(strs[i]);
        }
        vector<string> ret;
        for (auto iter = mp.begin() ; iter != mp.end() ; iter ++) {
            if (iter->second.size() > 1) {
                ret.insert(ret.end() , iter->second.begin() , iter->second.end());
            }
        }
        return ret;
    }
};