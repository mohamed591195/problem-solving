class TrieNode {
public:
    bool word = false;
    unordered_map<char, TrieNode*> children;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* currNode = root;
        for (char& ch: word) {
            if (!currNode->children.count(ch)) currNode->children[ch] = new TrieNode();
            currNode = currNode->children[ch];
        }
        currNode->word = true;
    }
    
    bool search(string word) {
       return DFSHelper(word, root, 0);
    }

    bool DFSHelper(string word, TrieNode* currNode, int idx) {
        if (idx == word.size()) return currNode->word;
         for (int i=idx; i<word.size(); ++i) {
            if (word[i] == '.') {
                for (auto& [ch, child]: currNode->children){
                    if (DFSHelper(word, child, i+1)) return true;
                }
                return false;
            }
            else if (currNode->children.count(word[i])) currNode = currNode->children[word[i]];
            else return false;
        }
        return currNode->word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */