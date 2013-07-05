class Solution {
private:
	bool checkmin(int &a,int b) {
		if (a > b) {
			a = b;
			return true;
		}
		return false;
	}
public:
	int threeSumClosest(vector<int> &num, int target) {
		int Min = 0x7fffffff;
		int ans = 0;
		sort(num.begin() , num.end());
		for (int i = 0 ; i < num.size() ; i ++) {
			for (int j = i + 1 ; j < num.size() ; j ++) {
				int lo = j + 1;
				int hi = num.size() - 1;
				int tar = target - num[i] - num[j];
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (num[mid] <= tar) lo = mid + 1;
					else hi = mid - 1;
				}
				for (int k = -1 ; k <= 0 ; k ++) {
					if (lo + k > j && lo + k < num.size()) {
						if (checkmin(Min , abs(num[lo+k] - tar))) {
							ans = num[lo+k] + num[i] + num[j];
						}
					}
				}
			}
		}
		return ans;
	}
};