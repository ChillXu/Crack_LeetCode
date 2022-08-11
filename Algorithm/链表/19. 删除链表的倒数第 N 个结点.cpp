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
//双指针，快指针先走N步
//
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head;
        for(int i=0;i<n;++i){
            fast=fast->next;
        }
        if(!fast){                //如果走完N步fast指针为空，说明当前slow指针指向的结点即为需要删除的结点
            head=head->next;      //ListNode *dummy=new ListNode(0,head); 可以避免边界条件的判定
            return head;
        }
        while(fast->next){        //需要考虑fast为nullptr！
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
