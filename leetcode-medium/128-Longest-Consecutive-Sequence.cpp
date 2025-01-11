class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int counter = 1;
        int maxStreak = 0;
        for(int i = 1; i<nums.size(); ++i){
            if (nums[i] == nums[i-1]) continue; 
            else if (nums[i] - nums[i-1] == 1) counter++;
            else {
                maxStreak = max(maxStreak, counter);
                counter = 1;
            }
        } 
        return max(maxStreak, counter);     
    }
};

/////////////////////////////////////////////////////// Another Sol //////////////////////////////////
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s = {nums.begin(), nums.end()};
        int maxStreak = 0;

        for(const auto& num: s){ // remember we're iterating over the s set (not nums vector)
            if (s.count(num-1)) continue;
            int temp = num + 1;
            while(s.count(temp)) temp += 1;
            maxStreak = max(maxStreak, temp - num);
        }   
        return maxStreak;
    }
};

/////////////////////////////////////////////////// DSU Sol ////////////////////////////////////////
class DSU{
    vector<int> parent;
    vector<int> rank;
    vector<int> size_;
public:
    DSU(int sz) {
        parent.resize(sz);
        rank.resize(sz, 0);
        size_.resize(sz, 1);

        for(int i=0; i<sz; ++i) {
            parent[i] = i;
        }
    }

    int find(int n){
        int root = n;
        while(root != parent[root]) root = parent[root];
        
        while(root != n){
            int temp = parent[n];
            parent[n] = root;
            n = temp;
        }
        return root;
    }

    bool uniond(int n1, int n2){
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) return false;

        if (rank[p1] > rank[p2]){
            parent[p2] = p1;
            size_[p1] += size_[p2];
        }
        else if (rank[p1] < rank[p2]){
            parent[p1] = p2;
            size_[p2] += size_[p1];
        }
        else {
            parent[p1] = p2;
            rank[p2]++;
            size_[p2] += size_[p1];
        }
        return true;
    }

    int getMaxSize(){
        return *max_element(size_.begin(), size_.end());
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> numIdxMap;

        for(int i=0; i<nums.size(); ++i) {
            if(numIdxMap.count(nums[i])) continue;
            numIdxMap[nums[i]] = i;
        }

        DSU dsu = DSU(nums.size());

         // Perform union operations for consecutive numbers, by testing it seems additional Union with (num + 1) is redundant 
        for (auto& [num, idx] : numIdxMap) {
            if (numIdxMap.count(num - 1)) {
                dsu.uniond(idx, numIdxMap[num - 1]);
            }
        }
        
        return dsu.getMaxSize();
    }
};

