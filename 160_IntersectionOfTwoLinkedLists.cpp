/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//46.76%
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
			return NULL;
		ListNode *ptrA(headA), *ptrB(headB);
		int flagA(0), flagB(0);
		while(ptrA != ptrB){
			if(!ptrA -> next)
				if(flagA)
					return NULL;
				else{
					flagA = 1;
					ptrA = headB;
				}
			else
				ptrA = ptrA -> next;
			
			if(!ptrB -> next)
				if(flagB)
					return NULL;
				else{
					flagB = 1;
					ptrB = headA;
				}
			else
				ptrB = ptrB -> next;
		}
		return ptrA;
    }
};

//Solution from LeetCode, which is more clear
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}

//Most elegant C++ solution from my view
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}