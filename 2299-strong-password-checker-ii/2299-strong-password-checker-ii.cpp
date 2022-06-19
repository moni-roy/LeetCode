class Solution {
private:
    string special = "!@#$%^&*()-+";
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8) return false;
        bool has_special = false, has_digit = false, has_lower = false, has_upper = false, has_repeat = true;
        for(int i = 0; i < password.size(); i++) {
            if(password[i] >= 'a' && password[i] <= 'z') {
                has_lower = true;
            } else if(password[i] >= 'A' && password[i] <= 'Z') {
                has_upper = true;
            } else if(password[i] >= '0' && password[i] <= '9') {
                has_digit = true;
            } else {
                has_special = true;
            }
            if(i > 0 && password[i] == password[i - 1]) {
                has_repeat = false;  
            } 
        }
        return has_special && has_digit && has_lower && has_upper && has_repeat;
    }
};