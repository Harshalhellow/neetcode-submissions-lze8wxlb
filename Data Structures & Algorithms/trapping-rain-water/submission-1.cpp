class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;  // Edge case: empty array

        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];  // Update left max height
                } else {
                    totalWater += leftMax - height[left];  // Water trapped
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];  // Update right max height
                } else {
                    totalWater += rightMax - height[right];  // Water trapped
                }
                right--;
            }
        }
        return totalWater;
    }
};

