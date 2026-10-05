class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size(); 
        int left = 0;
        int right = (m*n)-1;
        int mid;
        while(left<=right){
            mid = right+(left-right)/2; 
            if(matrix[mid/m][mid%m]>target) right = mid-1;
            else if(matrix[mid/m][mid%m]<target) left = mid+1; 
            else return true;
        }
        return false; 
    }
};
