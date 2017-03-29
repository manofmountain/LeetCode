//71.61%
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
			return true;
		stack<int> states;
		int curr(0);
		if(preorder[0] == '#' && 1 == preorder.size())
			return true;
		while(curr < preorder.size()){
			if(preorder[curr] == '#'){
				if(!states.empty()){
					++states.top();
					while(states.top() == 2){
						states.pop();
						if(!states.empty())
							++states.top();
						else{
							if(curr == preorder.size() - 1)
								return true;
							else
								return false;
						}
					}
				}else
					return false;
			}else if(preorder[curr] != ','){
				states.push(0);
				while(curr < preorder.size() && preorder[curr] != ',')
					++curr;
			}
			++curr;
		}
		return states.empty();
    }
};

//An elegant Java method
public boolean isValidSerialization(String preorder) {
    String[] nodes = preorder.split(",");
    int diff = 1;
    for (String node: nodes) {
        if (--diff < 0) return false;
        if (!node.equals("#")) diff += 2;
    }
    return diff == 0;
}


public class Solution {
    public boolean isValidSerialization(String preorder) {
        // using a stack, scan left to right
        // case 1: we see a number, just push it to the stack
        // case 2: we see #, check if the top of stack is also #
        // if so, pop #, pop the number in a while loop, until top of stack is not #
        // if not, push it to stack
        // in the end, check if stack size is 1, and stack top is #
        if (preorder == null) {
            return false;
        }
        Stack<String> st = new Stack<>();
        String[] strs = preorder.split(",");
        for (int pos = 0; pos < strs.length; pos++) {
            String curr = strs[pos];
            while (curr.equals("#") && !st.isEmpty() && st.peek().equals(curr)) {
                st.pop();
                if (st.isEmpty()) {
                    return false;
                }
                st.pop();
            }
            st.push(curr);
        }
        return st.size() == 1 && st.peek().equals("#");
    }
}