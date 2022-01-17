class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t: tokens) {
            if(isSymbol(t)) {
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                if(t == "+") st.push(f+s);
                else if(t == "-") st.push(f-s);
                else if(t == "*") st.push(f*s);
                else st.push(f/s);
            }
            else {
             st.push(stoi(t));   
            }
        }
        
        return st.top();
    }
    bool isSymbol(string s) {
        return (s == "+" || s=="-" || s == "*" || s == "/");
    }
    int toInt(string s) {
        stringstream ss(s);
        int t; ss>>t;
        return t;
    }
};