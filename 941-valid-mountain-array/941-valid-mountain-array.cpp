class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        return checkGreedily(arr);
    }
private:
    bool checkGreedily(vector<int> &arr) {
        int id = 0;
        while(id < arr.size() - 1 && arr[id] < arr[id+1]) id++;
        if(id == arr.size() - 1 || id == 0) return false;
        while(id < arr.size() - 1 && arr[id] > arr[id+1]) id ++;
        if(id != arr.size() - 1) return false;
        return true;
    }
};