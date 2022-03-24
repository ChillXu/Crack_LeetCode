//
//建立一个虚拟节点，将前两个节点与之后节点的交换操作统一
//
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode();
        ListNode *p=dummy,*s,*t=head;
        if(head && head->next){ //头节点不为空且需要至少有两个节点
            while(t && t->next){
                p->next=t->next;
                s=t->next;
                t->next=t->next->next;
                s->next=t;
                t=t->next;
                p=s->next;
            }
        }
        else{
            dummy->next=head;  //边界条件，缺少之后输入[1]会返回[]
        }
        return dummy->next;
    }
};
