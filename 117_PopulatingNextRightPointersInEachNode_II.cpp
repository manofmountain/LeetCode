//55.46%
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(!root)
			return;
		TreeLinkNode *pre(root), *curr(NULL);
		while(pre){
			curr = pre;
			while(curr){
				//most right node, rchild
				TreeLinkNode *rchild(curr -> right);
				if(curr -> left){
					if(curr -> right)
						curr -> left -> next = curr -> right;
					else
						rchild = curr -> left;
				}
				//most left child on next node
				curr = curr -> next;
				while(curr && !curr -> left && !curr -> right)
					curr = curr -> next;
				if(rchild && curr){
					TreeLinkNode *lchild(curr -> left);
					if(!curr -> left)
						lchild = curr -> right;
					rchild -> next = lchild;
				}
			}
			
			//Find starting point of next level
			while(pre){
				if(pre -> left){
					pre = pre -> left;
					break;
				}
				else if(pre -> right){
					pre = pre -> right;
					break;
				}
				else
					pre = pre -> next;
			}
		}						
    }
};

//A java iterative solution
public class Solution {
    
    //based on level order traversal
    public void connect(TreeLinkNode root) {

        TreeLinkNode head = null; //head of the next level
        TreeLinkNode prev = null; //the leading node on the next level
        TreeLinkNode cur = root;  //current node of current level

        while (cur != null) {
            
            while (cur != null) { //iterate on the current level
                //left child
                if (cur.left != null) {
                    if (prev != null) {
                        prev.next = cur.left;
                    } else {
                        head = cur.left;
                    }
                    prev = cur.left;
                }
                //right child
                if (cur.right != null) {
                    if (prev != null) {
                        prev.next = cur.right;
                    } else {
                        head = cur.right;
                    }
                    prev = cur.right;
                }
                //move to next node
                cur = cur.next;
            }
            
            //move to next level
            cur = head;
            head = null;
            prev = null;
        }
        
    }
}

//Another good solution
public class Solution {
    public void connect(TreeLinkNode root) {
        
        while(root != null){
            TreeLinkNode tempChild = new TreeLinkNode(0);
            TreeLinkNode currentChild = tempChild;
            while(root!=null){
                if(root.left != null) { currentChild.next = root.left; currentChild = currentChild.next;}
                if(root.right != null) { currentChild.next = root.right; currentChild = currentChild.next;}
                root = root.next;
            }
            root = tempChild.next;
        }
    }
}


//A good C++ one
void connect(TreeLinkNode *root) {
    TreeLinkNode *now, *tail, *head;
    
    now = root;
    head = tail = NULL;
    while(now)
    {
        if (now->left)
            if (tail) tail = tail->next =now->left;
            else head = tail = now->left;
        if (now->right)
            if (tail) tail = tail->next =now->right;
            else head = tail = now->right;
        if(!(now = now->next))
        {
            now = head;
            head = tail=NULL;
        }
    }
}