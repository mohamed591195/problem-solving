class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charFreq;
        for (char& ch: t){
            charFreq[ch]++;
        }
       
        int minStart = 0;
        int minLen = INT_MAX;
        int left = 0;
        int counter = 0;
        unordered_map<char, int> cacheMap;

        for(int i=0; i<s.size(); ++i){

            if (charFreq.find(s[i]) != charFreq.end()) {
            
                cacheMap[s[i]]++;
                if (cacheMap[s[i]] <= charFreq[s[i]]){
                    counter++;
                }

                while (counter == t.size()){
                    while (left < s.size() && charFreq.find(s[left]) == charFreq.end()) left++;
                    int currLen = i-left+1;
                    if (minLen > currLen){
                        minLen = currLen;
                        minStart = left;
                    }
                    cacheMap[s[left]]--;
                    if (cacheMap[s[left]] < charFreq[s[left]]) counter--;
                    left++;
                }
            }
        }
        return (minLen == INT_MAX)? \\: s.substr(minStart, minLen);
    }
};
