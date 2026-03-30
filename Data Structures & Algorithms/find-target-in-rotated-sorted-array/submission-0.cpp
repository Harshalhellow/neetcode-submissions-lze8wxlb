class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        int m;
        while(left<right){
            m= (left+right)/2;
            if(nums[m]>nums[right]) left = m+1;
            else if(nums[m]<nums[right]) right = m;
        }
        int offset = left; 
        left = 0;
        right = nums.size()-1;
        while(left<=right){
            m=(left+right)/2;
            if(nums[(m+offset)%nums.size()]>target) right = m-1;
            else if(nums[(m+offset)%nums.size()]<target) left = m+1; 
            else if(nums[(m+offset)%nums.size()]==target) return (m+offset)%nums.size();
        }
        return -1;


        
    }
};
