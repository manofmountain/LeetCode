
//0.1%
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(empty())
			return;
		if(!s2.empty())
			s2.pop();
		else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
    }

    // Get the front element.
    int peek(void) {
        if(empty())
			return -1;
		if(!s2.empty())
			return s2.top();
		else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
private:
	stack<int> s1, s2;
};

//Solution from LeetCode
class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    void pop(void) {
        peek();
        output.pop();
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};

//Solution from LeetCode by using a normal stack and a function stack
class Queue {
public:
    stack<int> s;
    
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
        return;
        
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s.size()==0);
    }
};