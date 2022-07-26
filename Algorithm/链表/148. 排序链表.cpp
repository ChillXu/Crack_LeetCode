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
 //归并排序（递归）
 //
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;   // 空节点或者单个节点时return
        ListNode *slow=head,*fast=head;
        ListNode *pre;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;    // 需要将左右两边链表断开！！
        return mergeTwoLists(sortList(head),sortList(slow));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* head=new ListNode();
        ListNode* cur=head;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next=l1?l1:l2;
        return head->next;
    }
};
