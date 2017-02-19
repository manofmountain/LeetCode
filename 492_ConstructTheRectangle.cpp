//37%
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width(sqrt(area));
		vector<int> res;
		while(width){
			if(area % width == 0){
				res.push_back(area / width);
				res.push_back(width);
				break;
			}
			width--;
		}
		return res;
    }
};