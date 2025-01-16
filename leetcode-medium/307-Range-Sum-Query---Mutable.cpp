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

// The following logic also correct:
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

///////////////////////////////////////////////////////////// same solution with different Segment Tree implementation ////////////////////////////////////////
class SegmentTree{
    int sum = 0; 
    int L, R;
    SegmentTree* left;
    SegmentTree* right;
public:
    SegmentTree(int total, int L, int R): sum{total}, L{L}, R{R}, left{nullptr}, right{nullptr} {}

    static SegmentTree* build(vector<int>& nums, int L, int R) {
        if (L == R) {
            return new SegmentTree(nums[L], L, R);
        }

        int M = L + (R - L) / 2;
        
        SegmentTree* root = new SegmentTree(0, L, R);
        root->left = SegmentTree::build(nums, L, M);
        root->right = SegmentTree::build(nums, M + 1, R);

        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    void update(int index, int val) {
        if (this->L == this->R) {
            this->sum = val;
            return;
        }

        int M = this->L + (this->R - this->L) / 2;
        if (index > M){
            this->right->update(index, val);
        }
        else {
            this->left->update(index, val);
        }
        this->sum = this->left->sum + this->right->sum;
    }

    int rangeQuery(int LL, int RR) {
        if (L == LL && R == RR){
            return this->sum;
        }

        int M = this->L + (this->R - this->L) / 2;

        if (LL > M) {
            return this->right->rangeQuery(LL, RR);
        }
        else if (RR <= M) {
            return this->left->rangeQuery(LL, RR);
        }
        return this->left->rangeQuery(LL, M) + this->right->rangeQuery(M+1, RR);
    }
};



class NumArray {
    SegmentTree* root;
public:
    NumArray(vector<int>& nums) {
        root = SegmentTree::build(nums, 0, nums.size()-1);
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
