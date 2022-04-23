//
//哈希表
//
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head){
            if(hash.count(head)){
                return true;
            }
            hash.insert(head);
            head=head->next;
        }
        return false;
    }
};

//
//快慢指针
//
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};
