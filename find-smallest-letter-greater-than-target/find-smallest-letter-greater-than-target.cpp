class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target == 'z') return letters[0];
        for(auto c: letters) {
            if(c > target) return c;
        }
        return letters[0];
    }
};