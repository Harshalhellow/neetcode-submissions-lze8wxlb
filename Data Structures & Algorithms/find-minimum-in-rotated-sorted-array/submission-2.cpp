class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int smallest = nums[left];
        int middle;
        while(left<=right){
            middle = (left+right)/2;
            if(nums[middle]>=nums[left]){
                if(smallest>nums[left]) smallest = nums[left];
                left = middle+1;
            }
            else{
                if(smallest>nums[right]) smallest = nums[right];
                right = right-1;

            }

        }

        return smallest; 
    }
};
