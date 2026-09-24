class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxleft = height[left];
        int maxright = height[right];
        int area; 
        int totalarea = 0;
        while(left<right){
            if(height[left]<height[right]){
                 area = maxleft-height[left];
                 if(area>0) totalarea += area; 
                 if(maxleft<height[left]) maxleft = height[left];
                 left++; 
            }
            else{
                area = maxright-height[right];
                 if(area>0) totalarea += area; 
                 if(maxright<height[right]) maxright = height[right];
                 right--; 
            }
        }

        return totalarea; 
    }
};
