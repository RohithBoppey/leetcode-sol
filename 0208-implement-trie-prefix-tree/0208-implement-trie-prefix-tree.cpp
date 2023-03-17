struct TrieNode{
    bool end;
    TrieNode* children[26];
    
//     init
    TrieNode(){
        end = false;
//         init each alphabet with NULL
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* iter = root;
        for(auto ch: word){
            if(iter->children[ch - 'a'] == NULL){
//                 some value is present
//                 hence linking to the next node
                iter->children[ch - 'a'] = new TrieNode();
            }
            iter = iter->children[ch - 'a'];
        }
//         the word is then complete
        iter->end = true;
    }
    
    bool search(string word) {
//         searching works similar to insert
//         we need to search the letter by letter
//         if not there, return false
        
//         in the last node also, we need to check whether the node is false and end or prefix
        TrieNode* iter = root;
        for(auto ch: word){
            if(iter->children[ch - 'a'] == NULL){
//                 letter not there
                return false;
            }
            iter = iter->children[ch - 'a'];
        }
        
//         the last node when iterated should not be false and also the node should contain the end
//         because there could be a case the word is a prefix but not an actual word
        return (iter != NULL) and (iter->end == true);
    }
    
    bool startsWith(string word) {
//         works similar to the search
//         but can directly return false once the search of the word is complete
        TrieNode* iter = root;
        for(auto ch: word){
            if(iter->children[ch - 'a'] == NULL){
//                 letter not there
                return false;
            }
            iter = iter->children[ch - 'a'];
        }
        return true;
    }   
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */