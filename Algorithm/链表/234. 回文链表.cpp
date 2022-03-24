//
//先使用快慢指针找到链表中点，然后把链表后半段翻转，最后比较两半是否相等
//
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head){                      //[1]算回文
            return false;
        }
        ListNode *fast=head,*slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode *pre=nullptr,*temp;
        while(head){
            temp=head->next;
            head->next=pre;
            pre=head;
            head=temp;
        }
        return pre;
    }
};

//
//将链表中的值复制到数组，再在数组中进行判断
//
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head){
            vals.emplace_back(head->val);
            head=head->next;
        }
        for(int i=0,j=vals.size()-1;i<j;++i,--j){
            if(vals[i]!=vals[j]){
                return false;
            }
        }
        return true;
    }
};
