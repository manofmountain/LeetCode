//1.86%
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //vector<int> curr;
		vector<int> last;
		for(auto i = 0; i <= rowIndex; i++){
			vector<int> curr(i + 1, 1);
			for(auto j = 1; j < i; j++){
				curr[j] = last[j - 1] + last[j];
			}
			last = curr;
		}
		return last;
    }
};