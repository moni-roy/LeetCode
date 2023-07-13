class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        while(word1.size()>0 && word2.size()>0){
            res+=word1[0];
            res+=word2[0];
            word1.erase(0,1);
            word2.erase(0,1);
        }
        if(word1.size()>0) res+=word1;
        if(word2.size()>0) res+=word2;
        return res;
    }
};