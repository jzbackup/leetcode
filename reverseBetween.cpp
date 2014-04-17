/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 关于reverse字符串，用这个方法，只有move在移动，把每个move填到anchor和cur之间，只要移动length-1次即可
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *anchor = dummy;
        dummy->next = head;
        
        for(int i = 0; i < m-1; i ++){
            if(!anchor->next)return head;
            anchor = anchor->next;
        }
        ListNode *cur = anchor->next;
        ListNode *move = NULL;
        //只有move移动，anchor和cur都不动
        for(int i = 0; i < n-m; i ++){
            move = cur->next;
            cur->next = move->next;
            move->next = anchor->next;
            anchor->next = move;
        }
        return dummy->next;
    }
};
