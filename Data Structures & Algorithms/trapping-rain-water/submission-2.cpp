class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int Maxleft = left;
        int Maxright = right;
        int totalwater = 0;

        while(left<right){
            if(height[Maxleft]<height[Maxright]){
                left++;
                if(height[Maxleft]-height[left]>0) totalwater += height[Maxleft]-height[left];
                if(height[Maxleft]<=height[left]) Maxleft = left;
            }

            else if(height[Maxleft]>=height[Maxright]){
                right--;
                if(height[Maxright]-height[right]>0) totalwater += height[Maxright]-height[right];
                if(height[Maxright]<=height[right]) Maxright = right;
            }
        }
        return totalwater;



    }
};



// have two pointers 
// one at 0 and one at the end
// have a max and a current 
// move the pointers depending on if the max is less than the left or right 
// depending on what you moved you use that minus from the current hiehgt 
// if the answere is above a 0 then you add it to a running total of water
// if the current position is higher than the pointer you moved i.e if you moved right and its higher than max right than you update max hieht
