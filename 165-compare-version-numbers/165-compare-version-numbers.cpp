class Solution {
public:
    int compareVersion(string version1, string version2) {
        // split version1 and version2 by '.'
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        // compare each element of v1 and v2
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            int n1 = stoi(v1[i]);
            int n2 = stoi(v2[j]);
            if (n1 > n2) return 1;
            else if (n1 < n2) return -1;
            i++;
            j++;
        }
        // if v1 is longer than v2, compare the rest of v1 with 0
        while (i < v1.size()) {
            int n1 = stoi(v1[i]);
            if (n1 > 0) return 1;
            i++;
        }
        // if v2 is longer than v1, compare the rest of v2 with 0
        while (j < v2.size()) {
            int n2 = stoi(v2[j]);
            if (n2 > 0) return -1;
            j++;
        }
        return 0;
    }

    vector<string> split(string s, char delim) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            res.push_back(item);
        }
        return res;
    }
};