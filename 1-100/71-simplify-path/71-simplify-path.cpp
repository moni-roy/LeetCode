class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string s;
        vector<string> path_vec;
        while (getline(ss, s, '/')) {
            if (s == "." || s == "") {
                continue;
            } else if (s == "..") {
                if (!path_vec.empty()) {
                    path_vec.pop_back();
                }
            } else {
                path_vec.push_back(s);
            }
        }
        string res = "";
        for (auto s : path_vec) {
            res += "/" + s;
        }
        if (res == "") {
            res = "/";
        }
        return res;
    }
};