class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		set<vector<int> > ret;
		sort(num.begin() , num.end());
		for (int i = 0 ; i < num.size() ; i ++) {
			for (int j = i + 1 ; j < num.size() ; j ++) {
				for (int k = j + 1 ; k < num.size() ; k ++) {
					int sum = target - num[i] - num[j] - num[k];
					int lo = k + 1 , hi = num.size() - 1;
					while (lo <= hi) {
						int mid = (lo + hi) >> 1;
						if (num[mid] == sum) {
							vector<int> temp;
							temp.push_back(num[i]);
							temp.push_back(num[j]);
							temp.push_back(num[k]);
							temp.push_back(num[mid]);
							ret.insert(temp);
							break;
						} else if (num[mid] < sum) {
							lo = mid + 1;
						} else {
							hi = mid - 1;
						}
					}
				}
			}
		}
		return vector<vector<int> >(ret.begin() , ret.end());
	}
};