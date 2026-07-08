class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = 0;

        while (low < high) {
            int guess = (low + high) / 2;

            if (nums[guess] < nums[guess + 1]) {
                res = guess + 1;
                low = guess + 1;
            } else {
                res = guess;
                high = guess;
            }
        }

        return res;
    }
};