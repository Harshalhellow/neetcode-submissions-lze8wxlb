class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> index; 
        int area = 0;
        int maxarea = 0; 
        for(int i=0; i<heights.size(); i++){
            int start = i;
            while(!index.empty()&&index.top().second>heights[i]){
                area = index.top().second * (i-index.top().first);
                start = index.top().first; 
                if(maxarea<area) maxarea = area; 
                index.pop(); 
            }
            index.push({start,heights[i]});
            
        }

        while(!index.empty()){
            area = index.top().second * (heights.size()-index.top().first);
            if(maxarea<area) maxarea = area; 
            index.pop(); 
        };

        return maxarea; 
    }
};
