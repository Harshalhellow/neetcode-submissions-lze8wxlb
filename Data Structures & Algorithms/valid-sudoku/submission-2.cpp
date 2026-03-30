class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<pair<char,bool>>> row,col,threebythree;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                row[i].push_back({j,false});
                col[i].push_back({j,false});
                threebythree[i].push_back({j,false});        
            }
        }

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int d = board[i][j]-'1';
                    if(row[i][d].second==true) return false; 
                    if(row[i][d].second==false) row[i][d].second = true;

                    if(col[j][d].second==true) return false; 
                    if(col[j][d].second==false) col[j][d].second = true;

                    if(threebythree[(i / 3) * 3 + (j / 3)][d].second==true) return false; 
                    if(threebythree[((i / 3) * 3 + (j / 3))][d].second==false) threebythree[(i / 3) * 3 + (j / 3)][d].second = true;
                    

                }
            }
        }

        return true; 
    }
};
