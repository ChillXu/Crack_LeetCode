/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}    //类构造函数初始化数据成员（非静态const成员）
 * };
 */
 

\\方法一：哈希表
\\
\\方法二：快慢指针
\\fast指针每次走两步，slow指针每次走一步，链表为a+b
\\第一次相遇fast比slow多走了几圈，f=s+nb,f=2s -> s=nb
\\即slow走过的路程为nb，而a+nb的位置在入口处，所以slow再走a步会回到入口处
\\若fast从第一次相遇后从head出发也是走a步，第二次相遇即为入口
\\
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast!=nullptr){
            slow=slow->next;
            if(fast->next==nullptr) return nullptr;  //注意判断fast->next是否为空指针！！
            else{fast=fast->next->next;}
            if(fast==slow){
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
