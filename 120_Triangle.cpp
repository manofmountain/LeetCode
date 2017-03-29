//33.79%
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
			return -1;
		for(int i = triangle.size() - 1; i >= 1; --i){
			for(int j = 0; j < triangle[i].size() - 1; ++j){
				triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
			}
		}
		return triangle[0][0];
    }
};

//Not change the input parameter in this way
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
        }
    }
    return minlen[0];
}

//Or like this
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};