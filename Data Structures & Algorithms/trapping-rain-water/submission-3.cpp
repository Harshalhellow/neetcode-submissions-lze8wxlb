class Solution {
public:
    int trap(vector<int>& height) {
        int prefix[height.size()];
        int suffix[height.size()];
        int leftmax = height[0];
        int rightmax = height[height.size()-1]; 
        int area = 0;
        for(int i=0; i<height.size(); i++){
            if(leftmax<height[i]) leftmax = height[i];
            prefix[i] = leftmax;
        }
        for(int j=height.size()-1; j>=0; j--){
            if(rightmax<height[j]) rightmax = height[j];
            suffix[j] = rightmax;
        }

        for(int i=0; i<height.size(); i++){
            if(min(prefix[i],suffix[i])!=0)  area += min(prefix[i],suffix[i]) - height[i]; 
        }

        return area; 
    }
};


