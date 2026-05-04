class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>answer;
        vector<int>curr; 
        int index = 0;
        int currSum = 0; 
        if(currSum == target)  answer.push_back(curr);
        combinationSumHelper(answer, index, target, currSum,curr,nums);
        return answer; 
    }
    void combinationSumHelper(vector<vector<int>>&answer, int index, int target,int currsum, vector<int>curr, vector<int>&nums){
        if(currsum == target) {
            answer.push_back(curr);
            return;
        } 
        if(index>=nums.size())return;
        if(currsum>target) return;
        curr.push_back(nums[index]);
        currsum += nums[index];
 
        combinationSumHelper(answer, index, target, currsum,curr,nums);
        curr.pop_back();
        currsum -=nums[index];
        combinationSumHelper(answer, index+1, target, currsum,curr,nums);
    }
};
// we  pick an integer
// we go through the rest of hte array in a loop 
// we keep picking integers until we have gone over the target
// if we hit the target then we add it to our answers if not we dont pick it 
// 