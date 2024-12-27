class TrieNode {
public:
    TrieNode(bool word=false): word{word} {};
    bool word;
    unordered_map<char, TrieNode*> children;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for (char& ch: word) {
            if (!currNode->children.count(ch)) currNode->children[ch] = new TrieNode();
            currNode = currNode->children[ch];
        }
        currNode->word = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for(char& ch: word){
            if (currNode->children.count(ch)) currNode = currNode->children[ch];
            else return false;
        }
        return currNode->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for(char& ch: prefix){
            if (currNode->children.count(ch)) currNode = currNode->children[ch];
            else return false;
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