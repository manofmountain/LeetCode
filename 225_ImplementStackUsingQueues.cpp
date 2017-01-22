//7.04%
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!first.empty())
			first.push(x);
		else
			second.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(empty())
			return;
		if(!first.empty()){
			while(first.size() != 1){
				second.push(first.front());
				first.pop();
			}
			first.pop();
		}else{
			while(second.size() != 1){
				first.push(second.front());
				second.pop();
			}
			second.pop();
		}
    }

    // Get the top element.
    int top() {
        if(empty())
			return 0;
		if(!first.empty())
			return first.back();
		return second.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty() && second.empty();
    }
private:
	queue<int> first, second;
};

//Better solution than mine which only use one queue
class Stack {
public:
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		que.pop();
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};