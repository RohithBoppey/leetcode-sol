struct TrieNode{
    bool end;
    TrieNode* children[26];
    
//     init
    TrieNode(){
        end = false;
//         init each alphabet with NULL
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};


class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* iter = root;
        for(auto ch: word){
            if(iter->children[ch - 'a'] == NULL){
//                 no value is present
//                 hence linking to the next node
                iter->children[ch - 'a'] = new TrieNode();
            }
            iter = iter->children[ch - 'a'];
        }
//         the word is then complete
        iter->end = true;
    }
    
    bool helperSearch(string word, TrieNode* root){
        TrieNode* iter = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
           if(ch == '.'){
//                should find the nearest not null and traverse
               for(int j = 0; j < 26; j++){
                   if(iter->children[j] != NULL){
//                        should use this to traverse and find
                       if(helperSearch(word.substr(i + 1), iter->children[j]) == true){
//                            somewhere true is found, so no need to check others
                           return true;
                       }
                   }
               }
               return false;
           }else{
//                just like regular search in trie
               if(iter->children[ch - 'a'] == NULL){
//                    is null, so mismatch
                   return false;
               }else{
                   iter = iter->children[ch - 'a'];
               }
           }
        }
        return (iter != NULL) and (iter->end == true);
    }
    
    bool search(string word) {
        return helperSearch(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */