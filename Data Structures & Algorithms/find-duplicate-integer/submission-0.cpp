class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast   =0;
        int slow = 0;
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }

        int slowest = 0;
        while(slow!=slowest){
            slow = nums[slow];
            slowest = nums[slowest];
        }
        return slowest;
        
    }
};

//