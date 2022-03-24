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

//
//递归
//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){     //list1先空了，则直接返回list2，从剩余的list2开始向前一轮合并链表
            return list2;
        }
        if(!list2){
            return list1;
        }
        if(list1->val<=list2->val){
            list1->next=mergeTwoLists(list1->next,list2);   //选择val小的list1节点作为递归返回时添加的节点
            return list1;                                   //返回当前位置链表指针
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};
