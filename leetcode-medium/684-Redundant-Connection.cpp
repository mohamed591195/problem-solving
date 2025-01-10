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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu = DSU(edges.size());
        for(const auto& edge: edges){
            if (!dsu.uniond(edge[0], edge[1])) return edge;
        }
        return {};
    }
};