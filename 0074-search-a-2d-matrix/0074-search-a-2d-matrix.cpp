class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m - 1;
        int res = -1;
        // Find the correct row
        while (low <= high) {
            int guess = low + (high - low) / 2;
            if (matrix[guess][0] <= target) {
                res = guess;
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        if (res == -1)
            return false;
        int LOW = 0;
        int HIGH = n - 1;
        // Search within the row
        while (LOW <= HIGH) {
            int guess = LOW + (HIGH - LOW) / 2;
            if (matrix[res][guess] == target)
                return true;
            else if (matrix[res][guess] < target)
                LOW = guess + 1;
            else
                HIGH = guess - 1;
        }
        return false;
    }
};
