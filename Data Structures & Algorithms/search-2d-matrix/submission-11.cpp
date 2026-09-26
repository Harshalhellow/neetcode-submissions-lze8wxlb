class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        int left =0;
        int right = (m*n)-1;
        int indexl =0;
        int indexr =0;
        int middle;
        while(left<=right){
            middle = (left+right)/2;
            indexl = middle%n;
            indexr = middle/n; 
            if(matrix[indexr][indexl]<target)left = middle+1;
            else if(matrix[indexr][indexl]>target)right = middle-1;
            else return true;  
        }

        return false;
    }
};
