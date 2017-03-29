//14.8%
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(nextNums.empty()){
			nextNums.push(Iterator::next());
			return nextNums.front();
		}
		return nextNums.front();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(nextNums.empty())
			return Iterator::next();
		int num(nextNums.front());
		nextNums.pop();
		return num;
	}

	bool hasNext() const {
	    return !nextNums.empty() || Iterator::hasNext();
	}
private:
	queue<int> nextNums;
};

//One java solution which is smarter than mine
class PeekingIterator implements Iterator<Integer> {  
    private Integer next = null;
    private Iterator<Integer> iter;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        iter = iterator;
        if (iter.hasNext())
            next = iter.next();
    }
    
    // Returns the next element in the iteration without advancing the iterator. 
    public Integer peek() {
        return next; 
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer res = next;
        next = iter.hasNext() ? iter.next() : null;
        return res; 
    }

    @Override
    public boolean hasNext() {
        return next != null;
    }
}

//Clearly a much smarter solution
class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};


//This one has the same thinking with the java one
class PeekingIterator : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    m_hasnext = Iterator::hasNext();
	    if (m_hasnext) m_next = Iterator::next();
	}

	int peek() {
        return m_next;
	}

	int next() {
	    int t = m_next;
	    m_hasnext = Iterator::hasNext();
	    if (m_hasnext) m_next = Iterator::next();
	    return t;
	}

	bool hasNext() const {
	    return m_hasnext;
	}
};