//
//先遍历headA，用unordered_set记录所有节点
//再遍历headB，查找节点是否在表中存在
//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode *temp=headA;
        while(temp){
            visited.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(visited.count(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};

//
//假设链表 headA 的不相交部分有 a 个节点，链表 headB 的不相交部分有 b 个节点，两个链表相交的部分有 c 个节点
//两个链表相交：1)若a=b，则在遍历完之前就会退出循环；2）若a!=b，则两指针会在遍历完 a+b+c 个节点后在相交处相遇
//两个链表不相交：1）若a=b，则在遍历完之后会退出，此时l1=l2=nullptr；2）若a!=b，则两指针会在遍历完 a+b 个节点后都指向nullptr             
//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB;
        while(l1!=l2){
            l1=l1?l1->next:headB;
            l2=l2?l2->next:headA;
        }
        return l1;
    }
};
