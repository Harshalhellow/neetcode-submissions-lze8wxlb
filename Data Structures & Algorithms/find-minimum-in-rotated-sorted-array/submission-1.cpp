class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int m;
        while(left<right){
            m = (left+right)/2;
            if(nums[m]>nums[right]) left = m+1;
            else if (nums[m]<nums[right]) right = m;
        }
        return nums[left];
    }
};
