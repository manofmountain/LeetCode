//66.07%
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		if(n < k){
			vector<vector<int>> res;
			return res;
		}
		
		vector<vector<int>> res;
        vector<int> vecN(n);
		vector<int> vecK(k);
		for(int i = 1; i <= n; i++)
			vecN[i - 1] = i;
		combineHelper(res, vecN, vecK, 0, n, k);
		return res;
    }
private:
	void combineHelper(vector<vector<int>>& res, vector<int>& vecN, vector<int>& vecK, int left, int right, int k){
		if(k == 0){
			res.push_back(vecK);
			return;
		}

		for(int i = left; i < right; i++){
			vecK[k - 1] = vecN[i];
			//swap(vecN[i], vecN[left]);
			combineHelper(res, vecN, vecK, i + 1, right, k - 1);
			//swap(vecN[i], vecN[left]);
		}
	}		
};


//A brilliant iterative solution from LeetCode with comments
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c(k, 0); // vector of length k, all 0s
        int i = 0;
        while (i >= 0) {
            // Increment element at index i
            c[i]++;
            cout << "Incremented element at index " << i << endl;
            cout << toString(c) << endl;
            
            /* Move index to the left if the element
             * at index i has exceeded n.
             */
            if (c[i] > n) {
                i--;
                cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
            }
            
            /* If the index is at the end of the vector
             * c, then (because the other conditions are
             * obeyed), we know we have a valid combination,
             * so push it to our ans vector<vector<>>
             */
            else if (i == k - 1) {
                ans.push_back(c);
                cout << "Combination found!" << endl;
                cout << "Added " << toString(c) << " as an answer!" << endl;
            }
            
            /* Move index to the right and set the
             * element at that index equal to the
             * element at the previous index.
             * 
             * Because of the increment at the beginning
             * of this while loop, we ensure that the
             * element at this index will be at least
             * one more than its neighbor to the left.
             */
            else {
                i++;
                c[i] = c[i - 1];
                cout << "Moved index to the right, and copied the value"
                << " from the left" << endl;
                cout << toString(c) << endl;
            }
        }
        return ans;
    }
};

//This one is better than mine, cause the vec is non-needed
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp(0,k);
        combine(res,temp,0,0,n,k);
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
            }
        }
};