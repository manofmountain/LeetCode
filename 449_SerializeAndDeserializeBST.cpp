//33.33%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
			return "#";
		
		string res(to_string(root -> val) + ',');
		string leftRes(serialize(root -> left)), rightRes(serialize(root -> right));
		return res + to_string(leftRes.size()) + ',' + to_string(rightRes.size()) + ',' + leftRes + rightRes;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#")
			return NULL;
		
		//Locate ending position of root 'val'
		size_t posRoot(data.find_first_of(','));
		TreeNode *root = new TreeNode(stoi(data.substr(0, posRoot)));
		
		//Locate ending position of leftSize
		size_t posLeft = data.find_first_of(',', posRoot + 1);
		size_t posRight = data.find_first_of(',', posLeft + 1);
		int leftSize(stoi(data.substr(posRoot + 1, posLeft - posRoot))), rightSize(stoi(data.substr(posLeft + 1, posRight - posLeft)));
		root -> left = deserialize(data.substr(posRight + 1, leftSize));
		root -> right = deserialize(data.substr(posRight + 1 + leftSize, rightSize));
		return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//A better way and they use a more compact way to express the solution
 // Encodes a tree to a single string.
    void serialize(TreeNode* root, ostringstream& out )
    {
        if ( !root ) return;
        out << root->val << ",";
        serialize(root->left, out);
        serialize(root->right, out);
    }
    
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(const string& s, int lower, int upper, int & pos )
    {
        // pos is a variable to record the end of decoded buffer 
        if ( pos == s.size() ) return nullptr;
        int cur_pos = pos;
        int number = 0;
        while( s[cur_pos] != ',')
        {
            number = number * 10 + s[cur_pos] - '0';
            ++cur_pos;
        }
        ++cur_pos;
        // The next number is not part of current subtree, should return nullptr
        if ( number < lower || number > upper ) return nullptr;

        TreeNode* root = new TreeNode( number );
        pos = cur_pos; // update pos 
        root->left =  deserialize( s, lower, root->val, pos );
        root->right = deserialize( s, root->val, upper, pos );
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize( data, INT_MIN, INT_MAX, pos );
        
    }