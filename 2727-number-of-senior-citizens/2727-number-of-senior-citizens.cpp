class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCitizens = 0;
        for (auto& detail: details) {
            if ((detail[11] > '6') || (detail[11] == '6' && detail[12] > '0')) {
                seniorCitizens ++;
            }
        }
        return seniorCitizens;
    }
};