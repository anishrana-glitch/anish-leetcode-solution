class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (nums[guess] == target)
                return guess;

            // guess is in the left sorted part
            if (nums[guess] > nums[n - 1]) {

                if (target > nums[n - 1]) {
                    // target is also in the left part
                    if (nums[guess] > target)
                        high = guess - 1;
                    else
                        low = guess + 1;
                } else {
                    // target is in the right part
                    low = guess + 1;
                }
            }

            // guess is in the right sorted part
            else {

                if (target <= nums[n - 1]) {
                    // target is also in the right part
                    if (nums[guess] > target)
                        high = guess - 1;
                    else
                        low = guess + 1;
                } else {
                    // target is in the left part
                    high = guess - 1;
                }
            }
        }

        return -1;
    }
};