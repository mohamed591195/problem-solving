class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;
        for (int i=0; i < haystack.size(); ++i ){
            if (needle[0] == haystack[i] && haystack.substr(i, needle.size()) == needle) return i;
            // while(needle[j] == haystack[i] && j < needle.size() && i < haystack.size()){
            //     j++; i++;
            // }
            // if (j == needle.size()) return i-j;
            // j = 0;
        }
        return -1;
    }
};