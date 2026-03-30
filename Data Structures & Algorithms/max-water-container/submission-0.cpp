class Solution {
public:
    int maxArea(vector<int>& heights) {
        int a = 0;
        int b = heights.size()-1;
        int Maxarea = 0;
        int currentarea = 0;
        while (a<b){
            currentarea = min(heights[a],heights[b]) * (b-a);
            Maxarea = max(Maxarea,currentarea);
            if(heights[a]>heights[b]){
                b--;
            }
            else {
                a++;
            }
           
         
        }
        return Maxarea;
        
    }
};


// create two pointers 
// find the difference between where the are as the width and the smallest betweeen two as the highet 
// calculate area 
// having a biggest area and a cruent area
// return the biggest area 
// o n time o 1 space 
