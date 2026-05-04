class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answers;
        int index = 0;
        vector<int>curr;
        answers.push_back(curr);
        subsetshelper(answers,curr,nums,index);
        return answers;
    }
    void subsetshelper(vector<vector<int>>&answers, vector<int>curr, vector<int>&nums,int index){
        if(index==nums.size()) return;
        curr.push_back(nums[index]);
        answers.push_back(curr);
        subsetshelper(answers,curr,nums,index+1);
        curr.pop_back();
        subsetshelper(answers,curr,nums,index+1);
    }
};


// tree 
// give  a current numbers thing and have a global answers
// for each call push it to current push that to global then pop it and then make a call 
