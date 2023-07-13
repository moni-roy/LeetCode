class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstId = 0, secondId = 0;
        vector<vector<int>> ans;
        
        while(firstId < firstList.size() && secondId < secondList.size()) {
            auto first = firstList[firstId];
            auto second = secondList[secondId];
            
            int start = max(first[0], second[0]);
            int end = min(first[1], second[1]);
            
            if(start <= end) ans.push_back({start, end});
            if(end == first[1]) firstId ++;
            if(end == second[1]) secondId ++;
        }
        return ans;
    }
};