class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            if(!curr->children.contains(word[i])) curr->children[word[i]] = new TrieNode();
            curr = curr->children[word[i]];
            
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            if(!curr->children.contains(word[i])) return false;
            curr = curr->children[word[i]];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.size(); i++){
            if(!curr->children.contains(prefix[i])) return false;
            curr = curr->children[prefix[i]];
        }

        return true;
        
    }
};


// need to create a root node that has the char blank  and is word to false
// for each node it should have a hashmap with a character and a a node pointer to that 
//