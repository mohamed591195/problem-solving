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

// another popular solution that also utilize the greedy strategy 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalSurplus = 0;
        int tank = 0;
        int start = 0;
        for (int i=0; i<n; ++i) {
            totalSurplus += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return (totalSurplus < 0) ? -1 : start;
    }
};
