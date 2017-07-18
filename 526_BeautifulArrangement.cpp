//61.83%
class Solution {
public:
    int countArrangement(int N) {
        //assert(N >= 1);
		vector<vector<int>> choices(N);
		for(int i = 1; i <= N; ++i){
			int times(2);
			while(times * i <= N)
				choices[i - 1].push_back(times++ * i);
			times = 2;
			while(i / times >= 1){
				if(i % times == 0){
					choices[i - 1].push_back(i / times);	
				}
				++times;
			}
			choices[i - 1].push_back(i);
		}
		
		vector<int> traced(N);
		int sum(0);
		countHelper(choices, traced, 0, sum);
		return sum;
    }
private:
	void countHelper(const vector<vector<int>>& choices, vector<int>& traced, int pos, int& sum){
		//int sum(0);
		for(int num : choices[pos]){
			if(traced[num - 1] == 0){
				traced[num - 1] = 1;
				if(pos == choices.size() - 1)
					sum += 1;
				else
					countHelper(choices, traced, pos + 1, sum);
				traced[num - 1] = 0;
			}
		}
		//return sum;
	}	
};


//An easy Java way
public class Solution {
    int count = 0;
    
    public int countArrangement(int N) {
        if (N == 0) return 0;
        helper(N, 1, new int[N + 1]);
        return count;
    }
    
    private void helper(int N, int pos, int[] used) {
        if (pos > N) {
            count++;
            return;
        }
        
        for (int i = 1; i <= N; i++) {
            if (used[i] == 0 && (i % pos == 0 || pos % i == 0)) {
                used[i] = 1;
                helper(N, pos + 1, used);
                used[i] = 0;
            }
        }
    }
}

//A C++ solution with the different idea
class Solution {
public:
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<N; ++i) vs.push_back(i+1);
        return counts(N, vs);
    }
    int counts(int n, vector<int>& vs) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n-1]);
                ans += counts(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
};