class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxinim =0;
        int current;
        int distance;
        int smallest;
        int i = 0;
        int j = heights.size()-1;
        while (i<j){
            smallest = min(heights[i],heights[j]);
            distance = j-i;
            current = distance*smallest;
            maxinim = max(current,maxinim);
            if(heights[i]<heights[j])i++;
            else if(heights[j]<heights[i])j--;
            else if(heights[j]==heights[i])i++;
        }

        return maxinim;
        
    }
};
