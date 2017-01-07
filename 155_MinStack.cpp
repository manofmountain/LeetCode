//53.28%
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        objs.push_back(x);
		if(minObjs.empty() || minObjs[minObjs.size() - 1] >= x)
			minObjs.push_back(x);
    }
    
    void pop() {
        if(objs.empty())
			return;
		if(objs[objs.size() - 1] == minObjs[minObjs.size() - 1])
			minObjs.pop_back();
		objs.pop_back();
    }
    
    int top() {
        if(objs.empty())
			exit(-1);
		return objs[objs.size() - 1];
    }
    
    int getMin() {
        if(objs.empty())
			exit(-1);
		return minObjs[minObjs.size() - 1];
    }
private:
	vector<int> objs;
	vector<int> minObjs;
};

//A Better solution from LeetCode which use two Stacks
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */