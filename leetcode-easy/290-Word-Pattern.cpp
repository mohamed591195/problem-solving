class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        string word;
        vector<string> words;

        stringstream ss(s);
        while (ss >> word){
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        for (int i=0; i<pattern.size(); ++i) {
            if (m.count(pattern[i]) && m[pattern[i]] != words[i]) return false;
            m[pattern[i]] = words[i];
        }
        m.clear();
        unordered_map<string, char> m2;

        for (int i=0; i<pattern.size(); ++i) {
            if (m2.count(words[i]) && m2[words[i]] != pattern[i]) return false;           
            m2[words[i]] = pattern[i];
        }

        return true;
    }
};