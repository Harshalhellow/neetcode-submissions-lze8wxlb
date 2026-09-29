class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle;
        while(left<=right){
            if(nums[left]<=nums[right]){
                while(left<=right){
                    middle = (left+right)/2;
                    if(nums[middle]==target) return middle;
                    else if(nums[middle]>target) right = middle-1;
                    else left = middle+1;
                }
                return -1; 
            }
            middle = (left+right)/2;
            if(nums[left]<=nums[middle]){
                if(nums[left]<=target&& target<=nums[middle]) right = middle;
                else left = middle+1; 
            }
            else if(nums[middle]<=nums[right]){
                if(nums[middle]<=target&&target<=nums[right]) left = middle; 
                else right = middle-1; 
            }

        }
        return -1; 
    }
};
