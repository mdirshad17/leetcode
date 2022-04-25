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
public:
    vector<int> v;
    int s;
    int sz;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	   sz=nums.size();
        s=0;
        for(int x:nums){
            v.push_back(x);
        }
        
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return v[s];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	  
        return v[s++];
	}
	
	bool hasNext() const {
	    return (s)<sz;
	}
};