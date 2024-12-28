class TrieNode {
public:
    TrieNode(int idx=-1): idx{idx} {}
    bool word = false;
    unordered_map<char, TrieNode*> children;
    int idx;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void addWord(string word, int idx) {
        TrieNode* currNode = root;
        for (char& ch: word) {
            if (!currNode->children.count(ch)) currNode->children[ch] = new TrieNode();
            currNode = currNode->children[ch];
            currNode->idx = idx;
        }
        currNode->word = true;
    }
    
    int search(string& pref, string& suff) {
        TrieNode* currNode = root;
        
        for(char& ch: suff + "{" + pref){
            if (currNode->children.count(ch)) currNode = currNode->children[ch];
            else return -1;
        }
        return currNode->idx;
    }
};

class WordFilter {
public:
    Trie trie;

    WordFilter(vector<string>& words) {
        trie = Trie();
        for (int k=0; k<words.size(); ++k) {
                for (int j=0; j<words[k].size(); ++j){
                    trie.addWord(words[k].substr(j) + "{" + words[k], k);
                }
        }
    }
    
    int f(string pref, string suff) {
        return trie.search(pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */