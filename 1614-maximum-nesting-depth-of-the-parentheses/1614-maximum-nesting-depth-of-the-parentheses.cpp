class Solution {
public:
    int maxDepth(string s) {
        int maxNestingDepth = 0;  // Track the maximum nesting depth encountered
        int currentDepth = 0;      // Track the current nesting depth while traversing
      
        // Iterate through each character in the string
        for (char& ch : s) {
            if (ch == '(') {
                // Opening parenthesis increases the current depth
                currentDepth++;
                // Update maximum depth if current depth exceeds it
                maxNestingDepth = max(maxNestingDepth, currentDepth);
            } else if (ch == ')') {
                // Closing parenthesis decreases the current depth
                currentDepth--;
            }
            // Other characters are ignored (digits, operators, etc.)
        }
      
        return maxNestingDepth;
    }
};
