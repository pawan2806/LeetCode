/*
 *Below is the interface for Iterator, which is already defined for you.
 ***DO NOT**modify the interface for Iterator.
 *
 *class Iterator {
 *		struct Data;
 *		Data* data;
 *public:
 *		Iterator(const vector<int>& nums);
 *		Iterator(const Iterator& iter);
 *
 *		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator: public Iterator
{
    public: int i = 0,
    n;
    vector<int> ans;
    PeekingIterator(const vector<int> &nums): Iterator(nums)
    {
        n = nums.size();
        ans = nums;
    }

   	// Returns the next element in the iteration without advancing the iterator.
    int peek() {
    
    if(i<n){
    return ans[i];
    }
    return -1;
    
    }

   	// hasNext() and next() should behave the same as in the Iterator interface.
   	// Override them if needed.
    int next()
    {
        if (i < n)
            return ans[i++];

        return -1;
    }

    bool hasNext() const
    {
        return i < n;
    }
};