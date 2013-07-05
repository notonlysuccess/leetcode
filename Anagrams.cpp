class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> ret;
		vector<pair<string,string> > vec;
		for (int i = 0 ; i < strs.size() ; i ++) {
			string temp = strs[i];
			sort(temp.begin() , temp.end());
			vec.push_back(make_pair(temp , strs[i]));
		}
		sort(vec.begin() , vec.end());
		bool flag = false;
		for (int i = 1 ; i < vec.size() ; i ++) {
			if (vec[i].first == vec[i-1].first) {
				ret.push_back(vec[i-1].second);
				flag = true;
			} else if (flag) {
				flag = false;
				ret.push_back(vec[i-1].second);
			}
		}
		if (flag) {
			ret.push_back(vec[vec.size() - 1].second);
		}
		return ret;
	}
};