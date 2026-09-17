class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> indexheighet; 
        int maxarea =0; 
        int area = 0;
        for(int i=0; i<heights.size(); i++){
            int start = i; 
            while(!indexheighet.empty()&&indexheighet.top().second>heights[i]){
                start = indexheighet.top().first;
                area = indexheighet.top().second*(i-indexheighet.top().first);
                if(area>maxarea) maxarea = area; 
                indexheighet.pop();
            }
            indexheighet.push({start,heights[i]});
        }

        while(!indexheighet.empty()){
                area = indexheighet.top().second*(heights.size()-indexheighet.top().first);
                if(area>maxarea) maxarea = area; 
                indexheighet.pop();
        }

        return maxarea; 
    }
};
