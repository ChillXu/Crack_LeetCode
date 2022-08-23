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
//题目：给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
//归并排序（递归）
//时间：O(nlogn)  空间：O(logn)
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


//
//归并排序（自底向上）
//时间：O(nlogn)  空间：O(1)
//先两个两个的merge，完成一趟后，再4个4个的merge，直到结束。（手动分割链表）
//
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *p=head;
        int len=0;
        while(p){
            p=p->next;
            len++;
        }
        ListNode* dummyhead=new ListNode();
        dummyhead->next=head;
        for(int size=1;size<len;size<<=1){
            ListNode *cur=dummyhead->next;    // 错误写法ListNode *cur=head; 因为循环中修改完的链表头为dummyhead->next，而不是head！！
            ListNode *left,*right;
            ListNode *tail=dummyhead;
            while(cur){
                left=cur;
                right=cut(left,size);
                cur=cut(right,size);
                tail->next=mergeTwoLists(left,right);    //  tail->next不会影响链表头
                while(tail->next){tail=tail->next;}
            }
        }
        return dummyhead->next;
    }
    // 背诵！！！
    ListNode* cut(ListNode* head, int n){   //将链表切掉前n个节点，并返回后半部分的链表头
        ListNode *pre;
        while(head && n){
            pre=head;
            head=head->next;
            n--;
        }
        if(!head) return nullptr;
        pre->next=nullptr;   // 断开链表
        return head;
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
