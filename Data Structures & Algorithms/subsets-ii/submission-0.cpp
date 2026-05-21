class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answers;
        vector<int> curr; 
        int index= 0;
        answers.push_back(curr);
        sort(nums.begin(),nums.end());
        subsetsWithDuphelper(nums,answers,curr,index);
        return answers;
    }
    void subsetsWithDuphelper(vector<int>& nums,vector<vector<int>>&answers, vector<int>&curr,int index){
        if(index==nums.size()) return;
        curr.push_back(nums[index]);
        answers.push_back(curr);
        subsetsWithDuphelper(nums,answers,curr,index+1);
        curr.pop_back();
        while(index+1<nums.size()&&nums[index]==nums[index+1]) index++;
        subsetsWithDuphelper(nums,answers,curr,index+1);
    }
};

// its creating subsets
// we just go through from the start                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
