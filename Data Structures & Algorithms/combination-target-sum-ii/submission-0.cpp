class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> answers;
        int index = 0; 
        int currsum = 0;
        vector<int>curr; 
        if(currsum==target) answers.push_back(curr);
        combinationSum2helper(candidates,answers,index,target,currsum,curr);
        return answers;
    }
    void combinationSum2helper(vector<int>&candidates, vector<vector<int>>&answers,int index, int target, int currsum, vector<int>&curr){
        if(currsum==target){
            answers.push_back(curr);
            return;
        }
        if(currsum>target) return; 
        if(index>=candidates.size()) return;
        for(int i=index; i<candidates.size(); i++){
            if(currsum>target) return; 
            if(i>index &&candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            currsum += candidates[i];
            combinationSum2helper(candidates,answers,i+1,target,currsum,curr);
            curr.pop_back();
            currsum -= candidates[i];
        }
        
        
    }
 };


// sort it 
// go through it index by index
// if the index is the same as the previous index keep skipping 
// add the number to it 
// remove it and start another one without it 