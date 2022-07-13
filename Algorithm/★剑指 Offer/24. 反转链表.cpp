/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//
//迭代
//
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr,*cur=head;
        while(cur){
            head=head->next;
            cur->next=pre;
            pre=cur;
            cur=head;
        }
        return pre;
    }
};

//
//递归
//
