class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        vector<vector<int>> answers; 
        sort(intervals.begin(),intervals.end());
        answers.push_back(intervals[0]);
        vector<int>* previous;
        for(int i=1; i<intervals.size(); i++){
            previous = &answers.back(); 
            if((*previous)[1]>=intervals[i][0]){
                (*previous)[1] =  max((*previous)[1], intervals[i][1]);
            }
            else{
                answers.push_back(intervals[i]);
            }
        }

        return answers;

    }
};