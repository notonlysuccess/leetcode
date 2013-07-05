class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		vector<int> left(n , 0);
		vector<int> right(n , 0);
		for (int i = 0 ; i < height.size() ; i ++) {
			int index = i;
			while (index > 0 && height[index-1] >= height[i]) {
				index = left[index - 1];
			}
			left[i] = index;
		}
		for (int i = height.size() - 1 ; i >= 0 ; i--) {
			int index = i;
			while (index + 1 < height.size() && height[index + 1] >= height[i]) {
				index = right[index + 1];
			}
			right[i] = index;
		}
		int ret = 0;
		for (int i = 0 ; i < height.size() ; i ++) {
			ret = max(ret , (right[i] - left[i] + 1) * height[i]);
		}
		return ret;
	}
};