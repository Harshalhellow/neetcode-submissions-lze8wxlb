class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix[0].size()*matrix.size()-1;
        int m; 
        int cols = matrix[0].size();
        while(left<=right){
            m = (left+right)/2;
            if(matrix[m/cols][m%cols]<target)   left = m +1;  
            else if(matrix[m/cols][m%cols]>target) right = m-1;
            else if(matrix[m/cols][m%cols]==target) return true; 

        }
        return false;
        
    }
};
