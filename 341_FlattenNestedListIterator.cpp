//A solution from LeetCode and it's a better way
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

//A DFS way to do it
class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

int next() {
    int result = nodes.top().getInteger();
    nodes.pop();
    return result;
}

bool hasNext() {
    while(!nodes.empty()) {
        NestedInteger curr = nodes.top();
        if(curr.isInteger()) {
            return true;
        }
        
        nodes.pop();
        vector<NestedInteger>& adjs = curr.getList();
        int size = adjs.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(adjs[i]);
        }
    }
    
    return false;
    }
};