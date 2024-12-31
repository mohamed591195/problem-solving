class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int currSize = 0;
        string currStr = \\; 
        for (int i=0; i<words.size(); ++i) {
            // calculating how many words to take, and the the size of them including the single inner space between 
            // each word and the next except last word;

            int j = i;
            // adding first word size without space (but this is easier, instead of doing calculation for the last word)
            // still the calculations are correct
            // we are adding single spaces, to make sure at the bare min space we can combine the words together
            // so later on if combined words with inner single space we are sure they would be <= maxWidth
            currSize += words[j++].size();
            while (j < words.size() && currSize + words[j].size() + 1 <= maxWidth) {
                currSize += (words[j++].size() + 1);
            }
            j--;

            // inner spaces count
            int innerWords = j-i;
            // all spaces combined
            int extraSpace = maxWidth - currSize + innerWords;

            if (j == words.size()-1) { // if we are in the last line
                // all words are left justified with a single space
                while(i < j) {
                    currStr += words[i++] + ' ';
                    extraSpace--;
                }
                currStr += words[i] + string(extraSpace, ' ');
                result.push_back(currStr);
                break;
            }

            // remaining spaces after equally distriputing the availabe space among words
            int remaining = innerWords? extraSpace % innerWords: 0;
            while (i < j){
                // if still remaining space, we add extra single space to the dedicated space to each word
                if (remaining){
                    currStr += words[i++] + string(extraSpace/innerWords + 1, ' ');
                    remaining--;
                }  
                else currStr += words[i++] + string(extraSpace/innerWords, ' ');   
            }
            // if innerWords == 0, means we only have one word, it also means i==j, i.e we didn't enter previous loop
            // so we add the word, with all available extraSpace after it
            if (innerWords == 0) currStr += words[i] + string(extraSpace, ' ');
            
            // else if we did enter the loop, just add the last word without any trailing spaces
            else currStr += words[i];

            result.push_back(currStr);
            currStr = \\;
            currSize = 0;
            innerWords = 0;
            i = j;
        }
        return result;
    }
};