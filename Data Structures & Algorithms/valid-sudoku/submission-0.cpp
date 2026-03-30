class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> col;
        map<pair<int,int>,unordered_set<char>> squares;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                pair<int, int> currentsquare = {i/3,j/3};
                if(board[i][j]=='.') continue;
                if(row[i].count(board[i][j])||
                col[j].count(board[i][j])||
                squares[currentsquare].count(board[i][j])) return false ;
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                squares[currentsquare].insert(board[i][j]);
            }

            
        }

        return true;

    }
};


//create arrays to hold each row and collums numbers 
// go through each 3by 3 thing keeping track of seem eleements 



 


// have three checks 
    // check if its in the set of all seen numbers 
    // check the row and col sets if its in them
    // if not put that number in all three sets 
    // if they are return false 
//if it goes through the whole for loop return false 

//o(n) time
// o(n) space 













