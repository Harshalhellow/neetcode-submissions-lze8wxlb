class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());

        for(int i=0; i<nums.size(); i++){
            if(i==0) left[i] = 1;
            else left[i] = left[i-1]* nums[i-1];
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(i==nums.size()-1) right[i] =1; 
            else right[i] = right[i+1]*nums[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            right[i] *= left[i];
        }

        return right; 
    }
};


/*
Another solution would be two different arrays 

one with the product of all numbers to the left of that index
one with the product of all numbers to the right of that index

than the final answer index would be to times both of these two vectors 

then we just give the rsuelt 

*/