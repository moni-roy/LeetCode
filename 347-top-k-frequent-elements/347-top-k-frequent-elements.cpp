class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return topKFrequentUsingQuickSelect(nums, k);
    }
private:
    vector<int> topKFrequentUsingPriorityQueue(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push({it->second, it->first});
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    vector<int> topKFrequentUsingQuickSelect(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> res;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            res.push_back(it->first);
        }
        quickSelect(res, 0, res.size() - 1, k, freq);
        return vector<int>(res.begin(), res.begin() + k);
    }

    void quickSelect(vector<int>& nums, int l, int r, int k, unordered_map<int, int>& freq) {
        if (l >= r) {
            return;
        }
        int partition = partitionIt(nums, l, r, freq);

        if (partition == k) {
            return;
        } else if (partition < k) {
            quickSelect(nums, partition + 1, r, k, freq);
        } else {
            quickSelect(nums, l, partition - 1, k, freq);
        }
    }

    int partitionIt(vector<int>& nums, int l, int r, unordered_map<int, int>& freq) {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (freq[nums[j]] >= freq[pivot]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
};