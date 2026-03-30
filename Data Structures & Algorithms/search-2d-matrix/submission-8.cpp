class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int k=0;
        bool updated = false;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]>target){
                k=i-1;
                updated = true;
                break;
            }
            else if(matrix[i][0]==target) return true;
        }
        if(k==-1)return false;
        if(updated == false) k = matrix.size()-1;
        
        int left = 0;
        int right = matrix[k].size()-1;
        int middle;
        while(left<=right){
            middle = (left+right)/2;
            if(matrix[k][middle]<target) left = middle+1;
            else if(matrix[k][middle]>target) right = middle-1;
            else return true;
        }
        return false; 
        
    }
};
