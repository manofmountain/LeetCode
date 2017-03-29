/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
//69.64%
//DFS solution, O(n) time + space
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head)
			return NULL;
        unordered_map<RandomListNode *, RandomListNode *> traced;
		return copyRandomListHelper(head, traced);
    }
private:
	RandomListNode *copyRandomListHelper(RandomListNode *head, unordered_map<RandomListNode *, RandomListNode *>& traced){
		if(!head)
			return NULL;
		if(traced.find(head) == traced.end()){
			traced[head] = new RandomListNode(head -> label);
			traced[head] -> next = copyRandomListHelper(head -> next, traced);
			traced[head] -> random = copyRandomListHelper(head -> random, traced);
		}
		return traced[head];
	}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
//74.67% O(n) time + space
//DFS solution in iterative way
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head)
			return NULL;
        unordered_map<RandomListNode *, RandomListNode *> traced;
		RandomListNode newHead(0);
		RandomListNode *curr(head), *prev(&newHead);
		while(curr){
			prev -> next = traced[curr] = new RandomListNode(curr -> label);
			prev = traced[curr];
			curr = curr -> next;
		}
		curr = head;
		while(curr){
			if(curr -> random)
				traced[curr] -> random = traced[curr -> random];
			curr = curr -> next;
		}
		return newHead.next;
    }
};

//A java solution which uses only O(1) space and O(n) time... Such a genious one
public RandomListNode copyRandomList(RandomListNode head) {
	RandomListNode iter = head, next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != null) {
		next = iter.next;

		RandomListNode copy = new RandomListNode(iter.label);
		iter.next = copy;
		copy.next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != null) {
		if (iter.random != null) {
			iter.next.random = iter.random.next;
		}
		iter = iter.next.next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode pseudoHead = new RandomListNode(0);
	RandomListNode copy, copyIter = pseudoHead;

	while (iter != null) {
		next = iter.next.next;

		// extract the copy
		copy = iter.next;
		copyIter.next = copy;
		copyIter = copy;

		// restore the original list
		iter.next = next;

		iter = next;
	}

	return pseudoHead.next;
}

//A C++ way to re-initialize this genious one
RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
        
    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        if (l1->random != NULL) l1->next->random = l1->random->next;
    }
        
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) l2->next = l2->next->next;
    }

    return newHead;
}