class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = n * m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int val = matrix[mid/m][mid%m];
            if (val == target) {
                return true;
            } else if (val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};