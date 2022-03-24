//
//
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode();
        ListNode* node=dummy;       //最终需要返回头节点，所以另创建一个指针用来合并
        while(list1 && list2){
            if(list1->val<=list2->val){
                node->next=list1;
                list1=list1->next;
            }
            else{
                node->next=list2;
                list2=list2->next;
            }
            node=node->next;
        }
        node->next=list1?list1:list2;
        return dummy->next;
    }
};
