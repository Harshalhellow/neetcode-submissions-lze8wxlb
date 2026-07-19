class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false; 
        // check for out of bounds case
        sort(nums.begin(),nums.end());
        // sort the vector 
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i]) return true; 
        }
        return false; 
        // for loop and we go through and see if it is true;

    }

};

/*
we sort the vector 
we go through the vector check if the anytwo numbers next to each other are the same if true return true
// if in the entire vector there is nothing then we know we have successedd

[1,2,4,5,4]
[1,2,4,5]
for loop going thorugh 

*/