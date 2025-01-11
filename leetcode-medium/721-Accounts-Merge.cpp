class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int sz) {
        parent.resize(sz+1);
        rank.resize(sz+1, 0);
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
        }
        else if (rank[p1] < rank[p2]){
            parent[p1] = p2;
        }
        else {
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu = DSU(accounts.size()+1);

        unordered_map<string, int> emailGroupMapper;

        for(int i=0; i<accounts.size(); ++i){
            for(int j=1; j<accounts[i].size(); ++j){
                if (emailGroupMapper.count(accounts[i][j])){
                    dsu.uniond(emailGroupMapper[accounts[i][j]], i);
                }
                else {
                    emailGroupMapper[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> accountsMap;
        for (auto& [email, i]: emailGroupMapper) {
            accountsMap[dsu.find(i)].push_back(email);
        }
        vector<vector<string>> result;

        for(auto& [i, emails]: accountsMap){
            sort(emails.begin(), emails.end());
            vector<string> curr = {accounts[i][0]};
            curr.insert(curr.end(), emails.begin(), emails.end());
            result.push_back(curr);
    
        }
        return result;
    }
};