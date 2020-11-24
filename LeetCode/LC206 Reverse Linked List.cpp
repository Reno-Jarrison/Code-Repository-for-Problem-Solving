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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL) 
            return NULL;
        ListNode *pre = NULL, *cur = head, *suc = head->next;
        while (true)
        {
            cur->next = pre, pre = cur;
            if (suc == NULL)
                break;
            cur = suc, suc = suc->next;
        }
        return cur;
    }
};