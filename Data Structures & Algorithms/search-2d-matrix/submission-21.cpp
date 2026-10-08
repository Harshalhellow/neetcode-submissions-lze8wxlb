class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0;
        int r = (m*n)-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
          if(matrix[mid/m][mid%m]<target) l = mid +1;
          else if(matrix[mid/m][mid%m]>target) r= mid-1;
          else return true;  
        }
    return false;
        
    }
};
