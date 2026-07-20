class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle = (left+right)/2;
        while(left<=right){
            if(nums[middle]>target) right = middle-1;
            if(nums[middle]<target) left = middle+1;
            if(nums[middle]==target) return middle; 
            middle = (left+right)/2;
        }
        return -1; 
    }
};


// we just use binary search 
// we start from left and right at the start and end 
// we find the middle if target larger than the middle then right = middle -1
// if the other way then the other thing