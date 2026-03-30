class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort array
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate `a`

            int b = i + 1, c = nums.size() - 1;  // Initialize two pointers

            while (b < c) {
                int sum = nums[i] + nums[b] + nums[c];

                if (sum == 0) {
                    res.push_back({nums[i], nums[b], nums[c]});

                    // Skip duplicate `b`
                    while (b < c && nums[b] == nums[b + 1]) b++;
                    // Skip duplicate `c`
                    while (b < c && nums[c] == nums[c - 1]) c--;

                    // Move to next distinct elements
                    b++;
                    c--;
                } 
                else if (sum < 0) {
                    b++;  // Increase sum
                } 
                else {
                    c--;  // Decrease sum
                }
            }
        }
        return res;
    }
};



// sort the array 
// fix a to the first input see if there are any corresponding two pointers that find b c 
// next input 
// make sure to check if there duplicates 