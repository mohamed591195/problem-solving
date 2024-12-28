class TrieNode {
public:
    bool word = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    void addWord(string word) {
        TrieNode* currNode = root;
        for (char& ch: word) {
            if (!currNode->children.count(ch)) currNode->children[ch] = new TrieNode();
            currNode = currNode->children[ch];
        }
        currNode->word = true;
    }
};

class Solution {
public:
    void DFSHelper(
        vector<vector<char>>& board, string& word, TrieNode* currNode, vector<vector<int>>& posMoves,
                        vector<string>& results, vector<vector<int>>& visited, int& rows, int& cols, int r, int c) {

        if (currNode->word) {
            results.push_back(word);
            currNode->word = false;
        }

        visited[r][c] = 1;
        
        for (int i=0; i<4; ++i) {
            int newR = r + posMoves[i][0];
            int newC = c + posMoves[i][1];

            if (min(newR, newC) < 0 || newR >= rows || newC >= cols || visited[newR][newC]) continue;

            if (currNode->children.count(board[newR][newC])){
                word += board[newR][newC];
                DFSHelper(board, word, currNode->children[board[newR][newC]], posMoves, results, visited, rows, cols, newR, newC);
                word.pop_back(); 
            }
        }
        visited[r][c] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();
        for (const string& word: words) {
            trie.addWord(word);
        }        

        int rows = board.size();
        int cols = board[0].size();

        vector<string> results;
        vector<vector<int>> possibleMoves {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int r=0; r<rows; ++r){
            for (int c=0; c<cols; ++c) {

                if (trie.root->children.count(board[r][c])) {
                    string word {board[r][c]};
                    DFSHelper(board, word, trie.root->children[board[r][c]], possibleMoves, results, visited, rows, cols, r, c);
                }

            }
        }
        return results;
    }
};