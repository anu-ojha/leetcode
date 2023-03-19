class TrieNode{
public:
    vector<TrieNode*> links;
    string item;
    
    TrieNode(){
        links = vector<TrieNode*>(26);
        item = "";
    }
};

class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(node->links[c-'a'] == NULL){
                node->links[c-'a'] = new TrieNode();
            }
            node = node->links[c-'a'];
        }
        //mark it as end
        node->item = word;
    }
    
    bool match(string word, int depth, TrieNode* node){
        //node->item != "" means the node is end
        if(depth == word.size()) return (node->item != "");
        char c = word[depth];
        // cout << depth << " " << c << endl;
        if(c != '.'){
            //recursive search
            return (node->links[c-'a'] != NULL) && match(word, depth+1, node->links[c-'a']);
        }else{
            //search for all its children
            for(int i = 0; i < node->links.size(); i++){
                if(node->links[i] != NULL){
                    if(match(word, depth+1, node->links[i])){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    
    bool search(string word) {
        return match(word, 0, root);
    }
};