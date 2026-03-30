class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle;
        if(target==nums[0]) return 0;
        while(left<right){
            middle = (left+right)+1/2;
            if(nums[middle]<target) left = middle+1;
            else if(nums[middle]>target) right = middle-1;
            else if(nums[middle]==target) return middle;
        }


        return -1;

        
    }
};



// create left and right 
// caluclate middle 
// see if middle is greater thna or less gthan right 
// move left to middle
// repeat until we have found the thing