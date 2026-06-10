class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int,int>colpos;
        unordered_map<int,int>rowpluscolpos;
        unordered_map<int,int>rowminuscolpos;
        vector<string> curr(n,string(n, '.'));
        vector<vector<string>> answers; 
        solveNQueenshelper(n,curr,answers,0,0,colpos,rowpluscolpos,rowminuscolpos);
        return answers; 
    }

    void solveNQueenshelper(int n, vector<string>&curr,vector<vector<string>>&answers,int row, int col,unordered_map<int,int>&colpos,unordered_map<int,int>&rowpluscolpos,unordered_map<int,int>&rowminuscolpos){
        if(colpos.size()==n) {
            answers.push_back(curr);
            return; };

        for(int i=row; i<n; i++){
            for(int j=col; j<n; j++){
                if(issafe(colpos,rowpluscolpos,rowminuscolpos,i,j)){
                   colpos[j] = 1;
                   rowpluscolpos[i+j] = 1;
                   rowminuscolpos[i-j] = 1; 
                   curr[i][j] = 'Q';
                   solveNQueenshelper(n,curr,answers,i+1,0,colpos,rowpluscolpos,rowminuscolpos);
                    colpos.erase(j);
                    rowpluscolpos.erase(i + j);
                    rowminuscolpos.erase(i - j);
                    curr[i][j] = '.';
                }
            }
        }
    };


    bool issafe(unordered_map<int,int>&colpos,unordered_map<int,int>&rowpluscolpos,unordered_map<int,int>&rowminuscolpos, int row, int col){
        if(colpos.contains(col)||rowpluscolpos.contains(row+col)||rowminuscolpos.contains(row-col)) return false; 
        else return true; 
    };
};


// we can have three different unordered sets each for the thing 
// we can go thorugh and recurrsively add a queen in each position in that row
// check if its safe
// if it is safe continue
// keep doing this untill all rows have a queen 
// if there is board with all queens one each row then boom we have found a valid map and add it to our thin
