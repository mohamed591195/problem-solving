class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cache(26, 0);

        for (int i=0; i<magazine.size(); ++i) {
            cache[magazine[i] - 'a'] += 1;
        }

        for (int i=0; i<ransomNote.size(); ++i) {
            if (!cache[ransomNote[i] - 'a']--) return false;
        }
        return true;
    }
};