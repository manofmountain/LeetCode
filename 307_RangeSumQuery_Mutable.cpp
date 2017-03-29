class NumArray {
public:
    NumArray(vector<int> nums):originalNums(nums), sumNums(nums) {
        for(int i = 1; i < sumNums.size(); ++i)
			sumNums[i] += sumNums[i - 1];
    }
    
    void update(int i, int val) {
        assert(i >= 0 && i < originalNums.size());
		changesTable[i] += (val - originalNums[i]);
		originalNums[i] = val;
    }
    
    int sumRange(int i, int j) {
		assert(i <= j);
        map<int, int>::iterator ite1 = changesTable.lower_bound(i);
		map<int, int>::iterator ite2 = changesTable.upper_bound(j);
		int res;
		if(i > 0)
			res = sumNums[j] - sumNums[i - 1];
		else
			res = sumNums[j];
		for(map<int, int>::iterator ite = ite1; ite != ite2; ++ite){
			res += ite -> second;
		}
		return res;
    }
private:
	vector<int> originalNums;
	vector<int> sumNums;
	map<int, int> changesTable;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
 
//A bucket method which is pretty efficient
class NumArray {
public:
    
    struct Bucket
    {
        int sum;
        vector<int> val;
    };
    
    int bucketNum;
    int bucketSize;
    vector<Bucket> Bs;

    NumArray(vector<int> nums) {
        int size = nums.size();
        int bucketNum = (int)sqrt(2*size);
        bucketSize = bucketNum/2;
        while(bucketSize * bucketNum<size) ++bucketSize;
        
        Bs.resize(bucketNum);
        for(int i=0, k=0; i<bucketNum; ++i)
        {
            int temp = 0;
            Bs[i].val.resize(bucketSize);
            for(int j=0; j<bucketSize && k<size; ++j, ++k)
            {
                temp += nums[k];
                Bs[i].val[j] = nums[k];
            }
            Bs[i].sum = temp;
        }
    }

    void update(int i, int val) {
        int x = i / bucketSize;
        int y = i % bucketSize;
        Bs[x].sum += (val - Bs[x].val[y]);
        Bs[x].val[y] = val;
    }

    int sumRange(int i, int j) {
        int x1 = i / bucketSize;
        int y1 = i % bucketSize;
		int x2 = j / bucketSize;
        int y2 = j % bucketSize;
        int sum = 0;

		if(x1==x2)
		{
			for(int a=y1; a<=y2; ++a)
			{
				sum += Bs[x1].val[a];
			}
			return sum;
		}

		for(int a=y1; a<bucketSize; ++a)
		{
			sum += Bs[x1].val[a];
		}
        for(int a=x1+1; a<x2; ++a)
        {
            sum += Bs[a].sum;
        }
        for(int b=0; b<=y2; ++b)
        {
            sum += Bs[x2].val[b];
        }
        return sum;
    }
};

//39.25%
//Segment tree which need to have further investigations
struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};
class NumArray {
    SegmentTreeNode* root;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }
   
    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            diff = modifyTree(i,val,root->right);
        } else {
            diff = modifyTree(i,val,root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);