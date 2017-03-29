/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//9.69%
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next)
			return;
		
		ListNode *fast(head -> next), *slow(head);
		bool even(true);
		while(fast){
			even = true;
			fast = fast -> next;
			slow = slow -> next;
			if(fast){
				even = false;
				fast = fast -> next;
			}
		}
		if(!even){
			fast = slow -> next;
			slow -> next = NULL;
		}else
			fast = slow;
		
		//Start inversing fast started list
		ListNode *prev(NULL);
		while(fast){
			ListNode *next(fast -> next);
			fast -> next = prev;
			prev = fast;
			fast = next;
		}
		
		//Starting to interleave these two lists
		ListNode *curr(head);
		fast = prev;
		while(fast){
			ListNode *next(curr -> next);
			curr -> next = fast;
			curr = next;
			if(even && curr == fast)
				return;
			next = fast -> next;
			fast -> next = curr;
			fast = next;
		}	
    }
};

//A good java solution
public void reorderList(ListNode head) {
            if(head==null||head.next==null) return;
            
            //Find the middle of the list
            ListNode p1=head;
            ListNode p2=head;
            while(p2.next!=null&&p2.next.next!=null){ 
                p1=p1.next;
                p2=p2.next.next;
            }
            
            //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
            ListNode preMiddle=p1;
            ListNode preCurrent=p1.next;
            while(preCurrent.next!=null){
                ListNode current=preCurrent.next;
                preCurrent.next=current.next;
                current.next=preMiddle.next;
                preMiddle.next=current;
            }
            
            //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
            p1=head;
            p2=preMiddle.next;
            while(p1!=preMiddle){
                preMiddle.next=p2.next;
                p2.next=p1.next;
                p1.next=p2;
                p1=p2.next;
                p2=preMiddle.next;
            }
        }

//Really a cool function		
// O(N) time, O(1) space in total
void reorderList(ListNode *head) {
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
    
    //for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
}