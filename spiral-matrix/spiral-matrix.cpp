class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int rb = 0, re = matrix.size()-1;
        int cb = 0, ce = matrix[0].size()-1;
        
        while(rb <= re && cb <= ce) {
            for(int i = cb; i <= ce; i++) ans.push_back(matrix[rb][i]);
            rb ++;
            for(int i = rb; i <= re; i++) ans.push_back(matrix[i][ce]);
            ce --;
            
            if(rb <= re) {
                for(int j = ce; j>=cb; j--) ans.push_back(matrix[re][j]);
                
            }
            re --;
            if(cb <= ce) {
                for(int i = re; i >= rb; i--) ans.push_back(matrix[i][cb]);
            }
            cb ++;
        }
        return ans;
    }
};