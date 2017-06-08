//O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty())
			return 0;
		unordered_map<int, int> table;
		for(int a : A){
			for(int b : B){
				int sumAB = a + b;
				if(table.find(sumAB) == table.end())
					table.insert(make_pair(sumAB, 1));
				else
					++table[sumAB];
			}
		}
		
		int cnt(0);
		for(int c : C){
			for(int d : D){
				int sumCD = -(c + d);
				if(table.find(sumCD) != table.end())
					cnt += table[sumCD];
			}
		}
		return cnt;
    }
};