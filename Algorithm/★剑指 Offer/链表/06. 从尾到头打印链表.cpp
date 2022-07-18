//
//反转链表
//
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
    vector<int> reversePrint(ListNode* head) {
        ListNode *pre=nullptr,*next;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        vector<int> array;
        while(pre){
            array.push_back(pre->val);
            pre=pre->next;
        }
        return array;
    }
};
