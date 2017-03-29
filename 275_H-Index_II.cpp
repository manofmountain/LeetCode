//23.9%
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
			return 0;
		int size(citations.size());
		for(int i = 1; i <= size; ++i)
			if(citations[size - i] < i)
				return i - 1;
		return size;
    }
};

//64.29%
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
			return 0;
		int size(citations.size());
		int left(1), right(size);
		int index(0);
		while(left <= right){
			int mid(left + (right - left) / 2);
			if(citations[size - mid] >= mid){
				index = mid;
				left = mid + 1;
			}else
				right = mid - 1;
		}
		return index;	
    }
};

//A c function
int hIndex(int* citations, int citationsSize) {
    int lo = 0, hi = citationsSize, mid, index = 0;
    while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        if (citations[citationsSize - mid - 1] > mid) {
            lo = mid + 1;
            index = lo;
        } else {
            hi = mid - 1;
        }
    }
    return index;
}