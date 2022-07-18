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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val) return head->next;    //判断需要删除头节点的情况！
        ListNode *pre=head,*cur=head->next;
        while(cur!=nullptr && cur->val!=val){
            pre=cur;
            cur=cur->next;
        }
        if(cur!=nullptr) pre->next=cur->next;
        return head;
    }
};
