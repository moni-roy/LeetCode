class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return canCompleteCircuitWithoutAppend(gas, cost);
    }
private:
    int canCompleteCircuitWithoutAppend(vector<int> &gas, vector<int> &cost) {
      int total = 0, cur = 0, index = 0;
      for(int i = 0; i < gas.size(); i++) {
        total += gas[i] - cost[i];
        cur += gas[i] - cost[i];
        if(cur < 0) {
          index = i + 1;
          cur = 0;
        }
      }
      return total < 0 ? -1 : index;
    }
    int canCompleteCircuitByAppend(vector<int> &gas, vector<int> &cost) {
        return 0;
    }
};
