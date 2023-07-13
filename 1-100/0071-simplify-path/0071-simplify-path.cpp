class Solution {
public:
    string simplifyPath(string path) {
        vector<string> path_stack;
        string temp = "";
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (temp == "..") {
                    if (!path_stack.empty()) {
                        path_stack.pop_back();
                    }
                } else if (temp != "." && temp != "") {
                    path_stack.push_back(temp);
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }
        if (temp == "..") {
            if (!path_stack.empty()) {
                path_stack.pop_back();
            }
        } else if (temp != "." && temp != "") {
            path_stack.push_back(temp);
        }

        string result = "";
        for (int i = 0; i < path_stack.size(); ++i) {
            result += "/" + path_stack[i];
        }
        if (result == "") {
            result = "/";
        }
        return result;
    }
};
