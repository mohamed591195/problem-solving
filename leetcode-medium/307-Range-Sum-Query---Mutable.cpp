class SegmentTree{
    int n;
    vector<int> tree;

    void updateTree(int idx, int val, int L, int R, int pos){
        if (L == R) {
            tree[pos] = val;
            return;
        }

        int M = L + (R - L) / 2;
        if (idx <= M) updateTree(idx, val, L, M, 2*pos+1);
        else updateTree(idx, val, M+1, R, 2*pos+2);

        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }

    int rangeSumQuery(int QL, int QR, int L, int R, int pos){
        
        if (QL == L && QR == R) return tree[pos];
        int M = L + (R - L) / 2;
        if (QR <= M) return rangeSumQuery(QL, QR, L, M, 2*pos+1);
        else if (QL > M) return rangeSumQuery(QL, QR, M+1, R, 2*pos+2);
        else return rangeSumQuery(QL, M, L, M, 2*pos+1) + rangeSumQuery(M+1, QR, M+1, R, 2*pos+2);
        
        // if (L > QR || R < QL) return 0;

        // if (QL <= L && QR >= R) return tree[pos];

        // int M = L + (R - L) / 2; 
        // return rangeSumQuery(QL, QR, L, M, 2*pos+1) + rangeSumQuery(QL, QR, M+1, R, 2*pos+2);
    }

public:
    SegmentTree(int size): n{size}{
        tree.resize(4*n, 0);
    }

    int rangeQuery(int QL, int QR) {
        return rangeSumQuery(QL, QR, 0, n-1, 0);
    }

    void update(int idx, int val) {
        updateTree(idx, val, 0, n-1, 0);
    }
};

class NumArray {
    SegmentTree* root;
public:
    NumArray(vector<int>& nums) {
        root = new SegmentTree(nums.size());
        for(int i=0; i<nums.size(); ++i) {
            root->update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        root->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return root->rangeQuery(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */