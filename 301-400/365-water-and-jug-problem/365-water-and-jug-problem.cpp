class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
       return targetCapacity <= jug1Capacity + jug2Capacity &&
              (targetCapacity == 0 ||
               (jug1Capacity > 0 && jug2Capacity > 0 &&
                (targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0)));
    }
};