class Solution {
public:
    string clearDigits(string s) {
        string answer;
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            if (isdigit(s[charIndex]) && !answer.empty()) {
                answer.pop_back();
            } else {
                answer += s[charIndex];
            }
        }
        return answer;
    }
};