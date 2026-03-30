class Trie{
    public:
        unordered_map<char,Trie*> child;
        bool endOfWord = false;
};

class Solution {
public:
    Trie* root;
    Solution() {
        root = new Trie();
    }
    vector<string> answer; 
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* curr = root; 
        for(int i=0; i<words.size(); i++){
            curr = root;
            for(int j=0; j<words[i].size(); j++){
                if(!curr->child.contains(words[i][j]))  curr->child[words[i][j]] = new Trie();
                curr = curr->child[words[i][j]];
            }
            curr->endOfWord = true;
        } // each word has been added to the trie

        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                string temp;
                vector<pair<int,int>>visted;
                dfs(board,temp,root,i,j,visted);
            }
        }

        return answer; 

    }

    void dfs(vector<vector<char>>&board,string &temp,Trie*curr, int i, int j,vector<pair<int,int>>&visted){
        if(find(visted.begin(),visted.end(),pair<int,int>{i,j})!=visted.end()) return;
        char character = board[i][j];
        temp.push_back(character);
        
        // put character into temp

        // if not in trie we end dfs
        if(!curr->child.contains(character)) {
            temp.pop_back();
            return;
        }
        curr = curr->child[character];
        
        // if its a full word then we add it to answer if not already in there
        if(curr->endOfWord){
            answer.push_back(temp);
            curr->endOfWord =  false;
        } 
        int maxi = board.size();
        int maxj = board[0].size();
        visted.push_back({i,j});
        if(i+1<maxi) dfs(board,temp,curr,i+1,j,visted);
        if(i-1>=0) dfs(board,temp,curr,i-1,j,visted);
        if(j+1<maxj) dfs(board,temp,curr,i,j+1,visted);
        if(j-1>=0) dfs(board,temp,curr,i,j-1,visted);
        temp.pop_back();
        visted.pop_back();

        // if the trie check does not return false then we go through and dfs all valid board position with temp
        
    }

    
};


// we create a tri
// we add all the words from words to it
// we go thorugb all elments in the board and apply is it valid
// isitvalid is a recursive function that checks by going through the trie level by level
// it will keep track of each level by having a a pramater called resultsofar that keeps track of the valid chars
// if it works it will try and push back it to a global answer variable if the answer variable already has it will not push back 