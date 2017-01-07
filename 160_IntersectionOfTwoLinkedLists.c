/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//12.86%
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB)
		return NULL;
	int lenA = 0, lenB = 0;
	struct ListNode *ptrA = headA, *ptrB = headB;
	while(ptrA){
		lenA++;
		ptrA = ptrA -> next;
	}
	while(ptrB){
		lenB++;
		ptrB = ptrB -> next;
	}
	//Ensure headA points to the longer list
	int diffLen = 0;
	if(lenA > lenB){
		diffLen = lenA - lenB;
	}else{
		diffLen = lenB - lenA;
		struct ListNode *ptrTemp = headA;
		headA = headB;
		headB = ptrTemp;
	}
	
	//Find the common node out
	ptrA = headA, ptrB = headB;
	while(diffLen--)
		ptrA = ptrA -> next;
	while(ptrA && ptrB){
		if(ptrA == ptrB)
			return ptrA;
		ptrA = ptrA -> next;
		ptrB = ptrB -> next;
	}
	return NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// My old solution before which clearly better
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    if(NULL == headA || NULL == headB)
		return NULL;
	
	//Two pointers ptrA & ptrB
	struct ListNode *ptrA, *ptrB;
	ptrA = headA;
	ptrB = headB;
	int flagA = 0;
	int flagB = 0;
	while(ptrA != ptrB)
	{
		if(NULL == ptrA -> next)
		{
			if(0 == flagA)
			{
				ptrA = headB;
				flagA = 1;
			}
			else
				return NULL;
		}
		else
			ptrA = ptrA -> next;

		if(NULL == ptrB -> next)
		{
			if(0 == flagB)
			{
				ptrB = headA;
				flagB = 1;
			}
			else
				return NULL;
		}
		else
			ptrB = ptrB -> next;
	}
	
	return ptrA;
}