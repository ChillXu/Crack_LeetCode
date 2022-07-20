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
 //分治法
 //
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *head=new ListNode();
        ListNode *cur=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
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
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l==r) return lists[l];
        if(l>r) return nullptr;       // 当输入为[]，l=0，r=-1
        int mid=l+(r-l)/2;
        return mergeTwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
};


//
//优先队列
//
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{         // 仿函数
            bool operator()(ListNode* a, ListNode* b){
                return a->val>b->val;        // 小顶堆，队尾大于队首
            }
        };
        priority_queue<ListNode*,vector<ListNode*>,cmp> que;
        for(auto node:lists){
            if(node) que.push(node);         // 先将每个链表的头节点入队
        }
        ListNode *head=new ListNode();
        ListNode *cur=head;
        while(!que.empty()){
            ListNode *node=que.top();
            que.pop();
            cur->next=node;
            cur=cur->next;
            if(node->next) que.push(node->next);   // 每出队一个节点，将其下一个节点入队
        }
        return head->next;
    }
};
