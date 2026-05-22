class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool exits = false;
        vector<char>curr; 
        int index =0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==word[index]){
                    curr.push_back(word[index]);
                    char temp = board[i][j];
                    board[i][j] = '0';
                    existhelper(board,word,curr,index+1,exits,i,j);
                    curr.pop_back();
                    board[i][j] =  temp; 
                }
            }
        }
        return exits;
        
    }
    void existhelper(vector<vector<char>>& board, string word,vector<char>&curr,int index,bool&exits,int i,int j){
        if(curr.size()==word.size()){
            exits = true; 
            return;
        }
        if(!(board.size()>i+1&&board[i+1][j]!='0'&&board[i+1][j]==word[index]||0<=i-1&&board[i-1][j]!='0'&&board[i-1][j]==word[index]||board[i].size()>j+1&&board[i][j+1]!='0'&&board[i][j+1]==word[index]||0<=j-1&&board[i][j-1]!='0'&&board[i][j-1]==word[index])) return;
        char temp; 
        if(board.size()>i+1&&board[i+1][j]!='0'&&board[i+1][j]==word[index]){
            curr.push_back(word[index]);
            temp = board[i+1][j];
            board[i+1][j] = '0';
            existhelper(board,word,curr,index+1,exits,i+1,j);
            curr.pop_back();
            board[i+1][j] = temp; 
        }
        if(0<=i-1&&board[i-1][j]!='0'&&board[i-1][j]==word[index]){
            temp = board[i-1][j];
            board[i-1][j] = '0';
            curr.push_back(word[index]);
            existhelper(board,word,curr,index+1,exits,i-1,j);
            curr.pop_back();
            board[i-1][j] = temp; 
        }
        if(board[i].size()>j+1&&board[i][j+1]!='0'&&board[i][j+1]==word[index]){
            temp = board[i][j+1];
            board[i][j+1] = '0';
            curr.push_back(word[index]);
            existhelper(board,word,curr,index+1,exits,i,j+1);
            curr.pop_back();
            board[i][j+1] = temp; 
        }
        if(0<=j-1&&board[i][j-1]!='0'&&board[i][j-1]==word[index]){
            temp = board[i][j-1];
            board[i][j-1] = '0';
            curr.push_back(word[index]);
            existhelper(board,word,curr,index+1,exits,i,j-1);
            curr.pop_back();
            board[i][j-1] = temp;
        }
    }
};


//we can start a dfs everytime we get a successful hit on the index we are looking for 
// look at all valid paths and pick a valid path pop it and go see if there are other valid paths 
// if there is no valid pahts and the word remains inclomplete we return that dfs
// if the size of curr reaches the size of the word we have madde it
