class Trie{
    public:
        unordered_map<char,Trie*> child;
        bool endOfWord = false;
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(int i=0; i<word.size(); i++){
            if(!curr->child.contains(word[i]))  curr->child[word[i]] = new Trie();
            curr = curr->child[word[i]];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word,root,0);
    };

    bool dfs(string word, Trie* root,int j){
        Trie* curr = root;
        for(int i=j; i<word.size(); i++){
            if(word[i]=='.'){
                for(auto& [ch, node] :curr->child){
                    if(dfs(word,node,i+1)) return true;
                }
                return false;
            }
            
            else{ 
                if(!curr->child.contains(word[i])) return false;

            }
            curr = curr->child[word[i]];
        }
        return curr->endOfWord;
    };
};
