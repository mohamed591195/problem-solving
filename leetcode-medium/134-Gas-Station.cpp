class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int counter = 0;
        int tank = 0;
        int idx = 0;
        int n = gas.size();
        for (int i=0; i<2*n; ++i) {
            // idx = i % n;
            idx = (i >= n)? i-n: i;
            if (counter == n) break;
            counter ++;
            tank += gas[idx] - cost[idx];
            if (tank < 0) {
                tank = 0;
                counter = 0;
            }
        }
        if (tank >= 0 && counter == n){
            return idx;
        }
        return -1;
    }
};