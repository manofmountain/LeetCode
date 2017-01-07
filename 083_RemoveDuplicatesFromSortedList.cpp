
//Fabulous code from LeetCode
return h && (h->next = deleteDuplicates(h->next)) && h->next->val == h->val ? h->next : h;