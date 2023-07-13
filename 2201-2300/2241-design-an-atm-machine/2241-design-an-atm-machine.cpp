class ATM {
private:
	vector <long long> noteCount;
	vector <long long> noteValue;
public:
    ATM() {
		this->noteCount = vector <long long> (5, 0);
		this->noteValue = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
		for (int i = 0; i < 5; i++) {
			noteCount[i] += banknotesCount[i];
		}
    }
    
    vector<int> withdraw(int amount) {
		vector <int> result(5, 0);
		vector <long long> copyCount = noteCount;
		for (int i = 4; i >= 0; i--) {
			if (amount >= noteValue[i]) {
				long long count = amount / noteValue[i];
				long long mn = min(count, noteCount[i]);
				result[i] = mn;
				amount -= mn * noteValue[i];
				noteCount[i] -= mn;
			}
		}
		if (amount > 0) {
			result = vector <int> (1, -1);
			noteCount = copyCount;
		}
		return result;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */