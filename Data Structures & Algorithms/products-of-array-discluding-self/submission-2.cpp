class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
             int runningtotal = 1;  // Product of all non-zero elements
        int Zeros = 0;         // Count of zeros

        // Step 1: Calculate product of all non-zero elements and count zeros
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                runningtotal *= nums[i];
            } else {
                Zeros++;
            }
        }

        vector<int> res(nums.size(), 0); // Initialize result array with zeros
        
        // Step 2: Handle different cases based on the number of zeros
        for(int i = 0; i < nums.size(); i++) {
            if(Zeros > 1) {
                // If more than one zero, all elements are zero (already initialized)
                res[i] = 0;
            }
            else if(Zeros == 1) {
                // If exactly one zero, only the position of that zero is non-zero
                if(nums[i] == 0) {
                    res[i] = runningtotal; // Product of all non-zero numbers
                } else {
                    res[i] = 0;  // All other elements are zero
                }
            }
            else { 
                // If no zeros, each element is total product divided by itself
                res[i] = runningtotal / nums[i];
            }
        }

        return res;

    }
};



// have a total product 
// have a exsepetion for 0
// have a counter for 2 0s 
// divide the toatl product with the indivitual unit 
