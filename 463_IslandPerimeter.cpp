class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //int widP(0), heightP(0);
		int res(0);
		int height(grid.size()), width(0);
		if(height)
			width = grid[0].size();
		bool flag(false); //when false in 'water', true in 'land'
		for(int i = 0; i < height; i++){
			flag = false;
			for(int j = 0; j < width; j++){
				if(grid[i][j]){
					//From 'water' to 'land'
					if(!flag){
						res++;
						flag = true;
					}
					//Up
					if(i == 0 || !grid[i -1][j])
						res++;
					//Down
					if(i == (height - 1) || !grid[i + 1][j])
						res++;					
				}else{
					//From 'land' to 'water'
					if(flag){
						res++;
						flag = false;
					}
				}
			}
			//The rightest side might encounter 'water'
			if(flag)
				res++;
		}
		return res;
    }
};
//A much more clear solution from LeetCode
int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }