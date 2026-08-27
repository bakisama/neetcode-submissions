class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = rows - 1;
        int desiredrow = -1;

        // Find the row that could contain target
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][cols - 1]) {
                desiredrow = mid;
                break;
            }
            else if (target < matrix[mid][0]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (desiredrow == -1)
            return false;

        // Binary search inside the row
        l = 0;
        r = cols - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[desiredrow][mid] == target)
                return true;
            else if (matrix[desiredrow][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};