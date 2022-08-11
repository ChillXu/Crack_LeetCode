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
//题目：重排链表为 L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
//先找中间节点，断开，后半部分链表反转，合并
//
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode *pre=nullptr,*next;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
 
    ListNode* middleNode(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){  // 条件判断！！！
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    void mergeList(ListNode* l1, ListNode* l2){   // 不创建新的头节点合并两个链表的方法！！！
        ListNode *tmp1,*tmp2;
        while(l1 && l2){
            tmp1=l1->next;      // 需要保存next节点！
            tmp2=l2->next;

            l1->next=l2;
            l1=tmp1;

            l2->next=tmp1;
            l2=tmp2;
        }
    }

    void reorderList(ListNode* head) {
        ListNode *mid=middleNode(head);
        ListNode *l1=head;
        ListNode *l2=mid->next;
        mid->next=nullptr;
        l2=reverseList(l2);
        mergeList(l1,l2);
    }
};
