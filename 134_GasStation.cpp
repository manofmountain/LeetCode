class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total(0), subsum(INT_MAX), start(0);
        for(int i = 0; i < n; ++i){
            total += gas[i] - cost[i];
            if(total < subsum) {
                subsum = total;
                start = i + 1;
            }
        }
        return (total < 0) ?  -1 : (start%n); 
    }
}

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};

//32.09%
//A better idea to use the simple principles listed like below:
/*
If car starts at A and can not reach B. Any station between A and B
can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must be a solution.
(Should I prove them?)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();++i) if((tank +=(gas[i]-cost[i]))<0) {start=i+1;total+=tank;tank=0;}
        return (total+tank<0)? -1:start;
    }
};

//32.09%
//O(n)time + O(1)space
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty() || cost.empty())
			return -1;
		int remainSum(0);
		int start(-1), end(-1);
		for(int i = 0; i < gas.size(); ++i){
			if(gas[i] >= cost[i]){
				if(start < 0){
					start = end = i;
					remainSum = gas[i] - cost[i];
				}else{
					remainSum += (gas[i] - cost[i]);
					end = i;
				}
			}else{
				if(gas[i] - cost[i] + remainSum >= 0){
					remainSum += (gas[i] - cost[i]);
					end = i;
				}
				else{
					remainSum = 0;
					start = end = -1;
				}
			}
		}
		if(remainSum >= 0 && end == gas.size() - 1){
			for(int i = 0; i < start; ++i){
				remainSum += (gas[i] - cost[i]);
				if(remainSum < 0)
					return -1;
			}
			return start;
		}else
			return -1;
    }
};

//32.09%
//O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty() || cost.empty())
			return -1;
		vector<int> remain(gas);
		for(int i = 0; i < gas.size(); ++i){
			remain[i] -= cost[i];
		}
		int remainSum(0);
		int start(-1), end(-1);
		for(int i = 0; i < remain.size(); ++i){
			if(remain[i] >= 0){
				if(start < 0){
					start = end = i;
					remainSum = remain[i];
				}else{
					remainSum += remain[i];
					end = i;
				}
			}else{
				if(remain[i] + remainSum >= 0){
					remainSum += remain[i];
					end = i;
				}
				else{
					remainSum = 0;
					start = end = -1;
				}
			}
		}
		if(remainSum >= 0 && end == remain.size() - 1){
			for(int i = 0; i < start; ++i){
				remainSum += remain[i];
				if(remainSum < 0)
					return -1;
			}
			return start;
		}else
			return -1;
    }
};

