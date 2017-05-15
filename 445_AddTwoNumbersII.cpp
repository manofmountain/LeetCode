//96.58%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
			return l2;
		if(!l2)
			return l1;
		
		vector<int> vec;
		ListNode *ptr1(l1), *ptr2(l2);
		while(ptr1 && ptr2){
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next;
		}
		
		
		//Make l1 the longer one
		if(ptr2){
			swap(l1, l2);
			swap(ptr1, ptr2);
		}
		ListNode *newStart(l1);
		while(ptr1){
			vec.push_back(newStart -> val);
			newStart = newStart -> next;
			ptr1 = ptr1 -> next;
		}
		
		ptr1 = newStart, ptr2 = l2;
		while(ptr1){
			vec.push_back(ptr1 -> val + ptr2 -> val);
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next;
		}
		
		int mark(0);
		for(auto ite = vec.rbegin(); ite != vec.rend(); ++ite){
			*ite += mark;
			if(*ite >= 10){
				*ite %= 10;
				mark = 1;
			}else
				mark = 0;
		}
		
		int start(1);
		ListNode *res(NULL);
		if(mark){
			start = 0;
			res = new ListNode(mark);
		}else
			res = new ListNode(vec[0]);
		ListNode *curr(res);
			
		for(int i = start; i < vec.size(); ++i){
			curr -> next = new ListNode(vec[i]);
			curr = curr -> next;
		}
			
		return res;
    }
};

//A good solution idea by using Stacks
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        
        while(l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        };
        while(l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }
        
        int sum = 0;
        ListNode list = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) sum += s1.pop();
            if (!s2.empty()) sum += s2.pop();
            list.val = sum % 10;
            ListNode head = new ListNode(sum / 10);
            head.next = list;
            list = head;
            sum /= 10;
        }
        
        return list.val == 0 ? list.next : list;
    }
}


//By reversing output linked list instead and using only O(1) extra space
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while( curr1 ){ curr1=curr1->next; n1++; }
        while( curr2 ){ curr2=curr2->next; n2++; } 
        curr1 = l1; curr2 = l2;
        while( n1 > 0 && n2 > 0){
            int sum = 0;
            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
            if( n2 > n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
            res = addToFront( sum, res );
        }
        curr1 = res; res = NULL;
        while( curr1 ){
            curr1->val += carry; carry = curr1->val/10;
            res = addToFront( curr1->val%10, res );
            curr2 = curr1; 
            curr1 = curr1->next;
            delete curr2;
        }
        if( carry ) res = addToFront( 1, res );
        return res;
    }
    ListNode* addToFront( int val, ListNode* head ){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
	
	
//A java recursive solution
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int size1 = getLength(l1);
        int size2 = getLength(l2);
        ListNode head = new ListNode(1);
        // Make sure l1.length >= l2.length
        head.next = size1 < size2 ? helper(l2, l1, size2 - size1) : helper(l1, l2, size1 - size2);
        // Handle the first digit
        if (head.next.val > 9) {
            head.next.val = head.next.val % 10;
            return head;
        }
        return head.next;
    }
    // get length of the list
    public int getLength(ListNode l) {
        int count = 0;
        while(l != null) {
            l = l.next;
            count++;
        }
        return count;
    }
    // offset is the difference of length between l1 and l2
    public ListNode helper(ListNode l1, ListNode l2, int offset) {
        if (l1 == null) return null;
        // check whether l1 becomes the same length as l2
        ListNode result = offset == 0 ? new ListNode(l1.val + l2.val) : new ListNode(l1.val);
        ListNode post = offset == 0 ? helper(l1.next, l2.next, 0) : helper(l1.next, l2, offset - 1);
        // handle carry 
        if (post != null && post.val > 9) {
            result.val += 1;
            post.val = post.val % 10;
        }
        // combine nodes
        result.next = post;
        return result;
    }
	
//This one is similar with mine
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> nums1, nums2;
    while(l1) {
        nums1.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2) {
        nums2.push_back(l2->val);
        l2 = l2->next;
    }

    int m = nums1.size(), n = nums2.size();
    int sum = 0, carry = 0;

    ListNode *head = nullptr, *p = nullptr;

    for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
        sum = carry;
        if(i >= 0) 
            sum += nums1[i];

        if(j >= 0)
            sum += nums2[j];

        carry = sum / 10;

        p = new ListNode(sum%10);
        p->next = head;
        head = p;
    }

    return head;
}
};