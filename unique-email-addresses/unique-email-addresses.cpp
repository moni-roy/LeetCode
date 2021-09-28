class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        for(auto email: emails) {
            int ignore = 0;
            string uniqueEmail = "";
            for(int index = 0; index < email.length(); index++ ){
                if(email[index] == '+') ignore = 1;
                else if(email[index] == '@') ignore = 2;
                if(ignore!=1 && (email[index]!='.' || ignore ==2)) uniqueEmail += email[index];
            }
            uniqueEmails.insert(uniqueEmail);
        }
        return uniqueEmails.size();
    }
};