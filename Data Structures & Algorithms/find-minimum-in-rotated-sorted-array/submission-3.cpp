class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int middle;
        while(left< right){
            if(nums[left]<nums[right]){
                return nums[left];
            }
            middle = (left+right)/2;
            if(nums[middle]>=nums[left]){
                left = middle+1;
            }
            else    right = middle;

            

        }
        return nums[left];
    }
};
