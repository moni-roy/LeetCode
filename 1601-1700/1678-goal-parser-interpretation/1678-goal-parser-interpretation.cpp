class Solution {
public:
    string interpret(string command) {
        string res;
        int i = 0;
        while (i < command.size()) {
            if (command[i] == 'G') {
                res += 'G';
                i ++;
            } else  {
                if(command[i+1] == 'a') {
                    res += "al";
                    i += 4;
                } else {
                    res += 'o';
                    i += 2;
                }
            }
        }
        return res;
    }
};