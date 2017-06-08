class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
		return false;
    }
};


//This Java solution like my first mind
   class Pair{
        int min, max;
        public Pair(int min, int max){
            this.min = min;
            this.max = max;
        }
    }
    public boolean find132pattern(int[] nums) {
        Stack<Pair> stack = new Stack();
        for(int n: nums){
            if(stack.isEmpty() || n <stack.peek().min ) stack.push(new Pair(n,n));
            else if(n > stack.peek().min){ 
                Pair last = stack.pop();
                if(n < last.max) return true;
                else {
                    last.max = n;
                    while(!stack.isEmpty() && n >= stack.peek().max) stack.pop();
                    // At this time, n < stack.peek().max (if stack not empty)
                    if(!stack.isEmpty() && stack.peek().min < n) return true;
                    stack.push(last);
                }
                
            }
        }
        return false;
    }
	
public class Solution {
    public boolean find132pattern(int[] nums) {
        if(nums.length<3) return false;
        Integer low = null, high = null;
        int start = 0, end = 0;
        while(start<nums.length-1){
            while(start<nums.length-1 && nums[start]>=nums[start+1]) start++;
            // start is lowest now
            int m = start+1;
            while(m<nums.length-1 && nums[m]<=nums[m+1]) m++;
            // m is highest now
            int j = m+1;
            while(j<nums.length){
                if(nums[j]>nums[start] && nums[j]<nums[m]) return true;
                j++;
            }
            start = m+1;
        }
        return false;
    }
}