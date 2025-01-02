// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         vector<int> mapp(127, -1);
//         unordered_set<int> sett;

//         for (int i=0; i<s.size(); ++i) {
//             if (mapp[s[i]] == -1 && !sett.count(t[i])) {
//                 mapp[s[i]] = t[i];
//                 sett.insert(t[i]);
//             }
//             else if (mapp[s[i]] == t[i]) continue;
//             else return false;
//         }
//         return true;
//     }
// };

// a nicer solution where we take a look from each one's perspective
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapp(127, -1);
        // unordered_set<int> sett;

        // from S perspective 
        for (int i=0; i<s.size(); ++i) {
            if (mapp[s[i]] == -1 || mapp[s[i]] == t[i]) mapp[s[i]] = t[i];
            else return false;
        }

        //reseting our vector_based map
        fill(mapp.begin(), mapp.end(), -1);

        // from T perspective
        for (int i=0; i<s.size(); ++i) {
            if (mapp[t[i]] == -1 || mapp[t[i]] == s[i]) mapp[t[i]] = s[i];
            else return false;
        }
        return true;
    }
};