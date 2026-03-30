class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int middle;
        while(low<=high){
            middle = (low+high)/2;
            if(nums[middle]<target){
                low = middle+1;
            }
            else if(nums[middle]>target){
                high = middle-1;
            }
            else{
                return middle;
            }
        }
        return -1;
        
    }
};
