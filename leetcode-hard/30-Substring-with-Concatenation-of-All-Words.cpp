class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        
        // s is too short edge case
        if (totalLen > s.size()) return result;
        
        //a map to store words with their frequency
        unordered_map<string, int> wordsCount;

        for (string& word: words){
            wordsCount[word]++;
        }
        // the first WordLen-1 indices are possible start points to look for valid permutations in the entire s 
        for (int i=0; i<wordLen; ++i) {
            int left = i; // left boundary for the current window 
            unordered_map<string, int> cacheMap; // frequency map for the current window
            int counter = 0; // count the number of the words in the current valid window

            // starting search from i to (s.size() - wordSize) we do that for each i from outer loop
            for(int j = i; j <= s.size() - wordLen; j += wordLen){
                // extract the current word;
                string word = s.substr(j, wordLen);

                // if it's unvalid word, reset and start from the next word
                if (wordsCount.find(word) == wordsCount.end()){
                    left = j + wordLen;
                    counter = 0;
                    cacheMap.clear();
                }
                else {
                    // update the cache and the counter
                    cacheMap[word]++;
                    counter++;

                    // if the frequency of the current word excceeds the valid value, we keep moving the left side
                    // of the window untill we decrease it to the right count
                    while(cacheMap[word] > wordsCount[word]){
                        string leftWord = s.substr(left, wordLen);
                        cacheMap[leftWord]--;
                        counter--;
                        left += wordLen;
                    }

                    // if the current valid window reach the valid words count, we add the left to the result 
                    if (counter == words.size()) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        cacheMap[leftWord]--;
                        counter--;
                        left += wordLen;
                    }
                }
            }
        }
        return result;
    }
};
