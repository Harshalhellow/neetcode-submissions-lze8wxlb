class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int counter = 0; 
        if(intervals.size()==0) return counter;
        vector<vector<int>> nonmerge; 
        sort(intervals.begin(), intervals.end());
        nonmerge.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int>&previous = nonmerge.back();
            if(previous[1]>intervals[i][0]){
                previous[1] = min(previous[1],intervals[i][1]);
                counter++;
            }
            else nonmerge.push_back(intervals[i]);

        }
        return counter;
    }
};


