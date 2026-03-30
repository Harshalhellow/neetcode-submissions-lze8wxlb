class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int smallest = heights[0];
        int currentlargest = 0;
        int current;
        int distance;
        for(int i=0; i<heights.size(); i++){
            smallest = heights[i];
            for(int j=i; j<heights.size(); j++){
                if(heights[j]<smallest) smallest = heights[j];
                distance = (j-i)+1;
                current = distance*smallest;
                if(current>currentlargest) currentlargest = current;
            }
        }
        

        return currentlargest;
    }
};
