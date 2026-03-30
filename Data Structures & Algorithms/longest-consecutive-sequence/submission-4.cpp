class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // If the array is empty, return 0
        if(nums.empty()) return 0;
        
        // Sort the array to bring consecutive numbers together
        sort(nums.begin(), nums.end());
        
        // Initialize streak counters
        int streak = 1; // Any number itself is a streak of at least 1
        int maxstreak = 1;
        
        // Iterate through the sorted array starting from the second element
        for(int i = 1; i < nums.size(); i++) {
            // Skip duplicate numbers to avoid incorrect streak count
            if(nums[i] == nums[i-1]) continue;
            
            // Check if the current number is consecutive to the previous
            if(nums[i] == nums[i-1] + 1) {
                streak++; // Increment the streak
            } else {
                // If not consecutive, update maxstreak and reset streak
                maxstreak = max(maxstreak, streak);
                streak = 1;
            }
        }
        
        // Final check to account for the last streak
        maxstreak = max(maxstreak, streak);
        
        // Return the longest consecutive sequence length
        return maxstreak;
    }
};


// brute force approach
// sort the array n log n 
// create a streak 
// see whats the biggest streak

// nlogn time
// n space 
