//
//Input: 1->2->3->4->5->nullptr
//Output: 5->4->3->2->1->nullptr
//
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr, *next;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

//
//递归
//以 1->2->3->4->5->nullptr 为例，先找到最后一个节点5
//然后将5指向4，1->2->3->4<->5
//最后将4指向空指针，1->2->3->4->5
//每次返回newhead 5
//
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){ //要先判断head是否为空，否则会访问空指针
            return head;
        }
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
};
