//2.15%
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	//assert(n >= 1);
	//if(!isBadVersion(n))
	//	return n + 1;
	int left, right;
	for(left = 1, right = n;left < right ;){
			int mid = (left >> 1) + (right >> 1);
			if(isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
	}
	//if(isBadVersion(right))
	return right;		
}