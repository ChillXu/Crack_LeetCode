/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//
//头插法（一次遍历）
//在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置。
//
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;    // 使用虚拟节点则不需要讨论left=0的情况
        for(int i=0;i<left-1;++i){
            pre=pre->next;
        }
        ListNode* curr=pre->next;
        ListNode* next;
        for(int i=0;i<right-left;++i){
            next=curr->next;
            curr->next=next->next;
            next->next=pre->next;
            pre->next=next;
        }
        return dummy->next;
    }
};
