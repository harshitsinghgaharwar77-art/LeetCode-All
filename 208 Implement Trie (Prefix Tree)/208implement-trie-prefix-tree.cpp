class TrieNode{
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->ch = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }
        else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string prefix){
        if(prefix.length() == 0){
            return true;
        }

        int idx = prefix[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }
        else{
            return false;
        }

        return startsWithUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};