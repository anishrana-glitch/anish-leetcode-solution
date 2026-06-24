class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int officer = 0;      
        int uniqueCount = 1;  
        for (int cm = 1; cm < nums.size(); cm++) {    
            if (nums[cm] == nums[cm - 1]) {
                continue;
            }
            nums[officer + 1] = nums[cm];
            officer++;
            uniqueCount++;
        }
        return uniqueCount;
    }
};