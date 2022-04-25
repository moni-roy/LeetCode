/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    Iterator* iter;
    int peeked;
    bool hasPeeked;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        hasPeeked = false;
        iter = new Iterator(nums);
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!hasPeeked) {
            peeked = iter->next();
            hasPeeked = true;
        }
        return peeked;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(hasPeeked) {
            int temp = peeked;
            hasPeeked = false;
            return temp;
        }
        return iter->next();
	}
	
	bool hasNext() const {
        return hasPeeked || iter->hasNext();
	}
};