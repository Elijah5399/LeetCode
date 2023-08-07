class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int nums = m * n;
        int low = 0, high = nums - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int row = mid / n, col = mid % n;
            int elem = matrix[row][col];
            if (target == elem) {
                return true;
            } else if (target < elem) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int row = low / n, col = low % n;
        return matrix[row][col] == target;
    }
};