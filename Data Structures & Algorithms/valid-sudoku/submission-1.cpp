class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,vector<char>> row;
        map<int,vector<char>> col;
        map<pair<int,int>,vector<char>> squares;
        pair<int,int> Squareint;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                char current = board[i][j];

                if(find(row[i].begin(),row[i].end(),current) != row[i].end()) return false;
                if(find(col[j].begin(),col[j].end(),current) != col[j].end())  return false;
                row[i].push_back(board[i][j]);
                col[j].push_back(board[i][j]);
                
                
                Squareint = {i/3,j/3};
                if(find(squares[Squareint].begin(),squares[Squareint].end(),current) != squares[Squareint].end()) return false;
                squares[Squareint].push_back(board[i][j]);
                

            }
        }
        return true;
    
    
    
    
    }

};


// create 9 rows 
// create 9 cols 
// have created the whole board
// if an element is already in a row or coll then you know its not valid 
// create 9 boards that are for each of the squares 
// you can access each square by diviision row col
